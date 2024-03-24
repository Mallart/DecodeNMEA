#include <stdio.h>
#include "nmea.h"
#include "file_io.h"

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
	char* trame_string = malloc(sizeof(char) * BUFFER_LENGTH + 1);
	CHECK_PTR(trame_string);
	if (argc < 2)
	{
		printf("\nVeuillez entrer une trame NMEA:\n");
		printf("\nExemple de trame NMEA: %s\n", NMEA_EXAMPLE);
		fgets(trame_string, BUFFER_LENGTH, stdin);
		trame_string[BUFFER_LENGTH] = '\0';
	}
	else
	{
		trame_string = str_insert(trame_string, argv[1], 0);
	}
	if (!validate(trame_string))
	{
		printf("\nLa trame n'est pas valide: %s", trame_string);
		exit(1);
	}
	NMEA trame = str_to_nmea(argc > 2 ? argv[1] : trame_string);
	log_nmea("log_nmea.txt", &trame);
	trame = *read_nmea("log_nmea.txt");
	printf("Heure de la trame: %s\n", nmea_get_heure(trame));
	printf("Latitude de la trame: %s\n", nmea_get_coord(trame, LATITUDE));
	printf("Longitude de le trame: %s\n", nmea_get_coord(trame, LONGITUDE));
}

