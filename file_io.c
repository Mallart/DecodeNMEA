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
*  Nom du fichier : file_io.c                                                 *
*                                                                             *
******************************************************************************/

void log_nmea(char* file_path, NMEA* nmea)
{
	FILE* f = fopen(file_path, "w");
	if (!f)
		return;
	char* nmea_to_string = nmea_to_str(nmea);
	fputs(nmea_to_string, f);
	fputs("; Informations sur la trame: \n", f);
	fputs(generate_comments(*nmea), f);
	fclose(f);
}

NMEA* read_nmea(char* file_path)
{
	FILE* f = fopen(file_path, "r");
	if (f)
	{
		NMEA* trame = parse_nmea(f);
		return trame;
	}
	return 0;
}

NMEA* parse_nmea(FILE* stream)
{
	CHECK_NV_PTR(stream);
	char str[BUFFER_LENGTH];
	fgets(str, BUFFER_LENGTH, stream);
	CHECK_NV_PTR(str);
	NMEA trame = str_to_nmea(str);
	NMEA* trame_ptr = &trame;
	return trame_ptr;
}
