#include <stdio.h>
#include "nmea.h"
#include "file_io.h"

#define DEFAULT_RECORD_PATH "nmea.txt"

/******************************************************************************
*  ASR => 4R2.04                                                              *
*******************************************************************************
*                                                                             *
*  N° de Sujet : 01                                                           *
*                                                                             *
*******************************************************************************
*                                                                             *
*  Intitulé : Analyse de trame GPS                                            *
*                                                                             *
*******************************************************************************
*                                                                             *
*  Nom-prénom1 : Allart Mathéo                                                *
*                                                                             *
*  Nom-prénom2 : Vallette Noé                                                 *
*                                                                             *
*  Nom-prénom3 :                                                              *
*                                                                             *
*  Nom-prénom4 :                                                              *
*                                                                             *
*******************************************************************************
*                                                                             *
*  Nom du fichier : main.c                                                    *
*                                                                             *
******************************************************************************/



// Dans ce programme, il est possible de saisir une trame NMEA a analyser durant l'execution du programme, ou alors
// dans la console apres le nom du programme.

void main(int argc, char** argv)
{
	char* record_path = "";
	char* trame_string = malloc(sizeof(char) * BUFFER_LENGTH + 1);
	CHECK_PTR(trame_string);
	NMEA trame;
	if (argc < 2)
	{
		printf("\nVeuillez entrer une trame NMEA:\n");
		printf("\nExemple de trame NMEA: %s\n", NMEA_EXAMPLE);
		fgets(trame_string, BUFFER_LENGTH, stdin);
		trame_string[BUFFER_LENGTH] = '\0';
		record_path = argc < 3 ? DEFAULT_RECORD_PATH : argv[2];
		if (!validate(trame_string))
		{
			printf("\nLa trame n'est pas valide: %s", trame_string);
			exit(1);
		}
		trame = str_to_nmea(argc > 2 ? argv[1] : trame_string);
		log_nmea(record_path, &trame);
	}
	else
	{
		record_path = argc > 2 ? argv[2] : DEFAULT_RECORD_PATH;
		// Lecture seulement
		if (str_compare(argv[1], "0", 1))
		{
			NMEA* trame_ptr = read_nmea(record_path);
			if (!trame_ptr)
			{
				printf("Erreur lors de la lecture du fichier \"%s\"", record_path);
				exit(-1);
			}
			trame = *read_nmea(record_path);
			trame_string = nmea_to_str(&trame);
		}
		// Ecriture puis lecture
		else
		{
			trame_string = str_insert(trame_string, argv[1], 0);
			trame = str_to_nmea(trame_string);
			log_nmea(record_path, &trame);
			printf("Trame sauvegardee a l'emplacement: \"%s\".\n", record_path);
			NMEA* trame_ptr = read_nmea(record_path);
			CHECK_PTR(trame_ptr);
			if (!trame_ptr)
			{
				printf("Erreur lors de la lecture du fichier \"%s\"", record_path);
				exit(-1);
			}
			trame = *trame_ptr;
		}
	}
	if (!validate(trame_string))
	{
		printf("\nLa trame n'est pas valide: %s", trame_string);
		exit(1);
	}

	// Affichage des donnees 

	printf("Lecture des donnees enregistrees a \"%s\": \n", record_path);
	printf("Heure de la trame: %s\n", nmea_get_heure(trame));
	printf("Latitude de la trame: %s\n", nmea_get_coord(trame, LATITUDE));
	printf("Longitude de le trame: %s\n", nmea_get_coord(trame, LONGITUDE));
	printf("Altitude: %fM\n", trame.altitude);
	printf("Nombre de satellites a portee lors de l'enregistrement de la trame: %d\n", trame.n_satellites_following);
	printf("Note de la qualite des donnees: %d\n", trame.fix_qualification);
	printf("Dilution de la precision: %f\n", trame.dop);
	printf("Taux de correction: %f\n", trame.correction);
	printf("Secondes de delai: %d\n", trame.elapsed_seconds_since_last_update);
	printf("ID de la station: %d\n", trame.dgps_id);
	printf("Checksum: %d\n", trame.checksum);
}

