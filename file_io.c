#include "file_io.h"

/******************************************************************************
*  ASR => 4R2.04                                                              *
*******************************************************************************
*                                                                             *
*  N� de Sujet : 01                                                           *
*                                                                             *
*******************************************************************************
*                                                                             *
*  Intitul� : Analyse de trame GPS                                            *
*                                                                             *
*******************************************************************************
*                                                                             *
*  Nom-pr�nom1 : Allart Math�o                                                *
*                                                                             *
*  Nom-pr�nom2 : Vallette No�                                                 *
*                                                                             *
*  Nom-pr�nom3 :                                                              *
*                                                                             *
*  Nom-pr�nom4 :                                                              *
*                                                                             *
*******************************************************************************
*                                                                             *
*  Nom du fichier : file_io.c                                                 *
*                                                                             *
******************************************************************************/

void log_nmea(char* file_path, NMEA* nmea)
{
	FILE* f;
	fopen_s(&f, file_path, "w+");
	if (!f)
		return;
	char* nmea_to_string = nmea_to_str(nmea);
	fwrite(nmea_to_string, sizeof(char), str_len(nmea_to_string), f);
	fclose(f);
}

NMEA* read_nmea(char* file_path)
{
	FILE* f;
	fopen_s(&f, file_path, "r");
	if (f)
	{
		NMEA* trame = parse_nmea(f);
		return trame;
	}
	return 0;
}

NMEA* parse_nmea(FILE* stream)
{
	CHECK_PTR(stream);
	char str[BUFFER_LENGTH];
	fgets(str, BUFFER_LENGTH, stream);
	CHECK_PTR(str);
	NMEA trame = str_to_nmea(str);
	return &trame;
}
