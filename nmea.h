#ifndef NMEA_START
#include "str.h"
#define NMEA_START "$GPGGA"
#define NMEA_MIN_N_FIELDS 15
#define NMEA_N_DECIMAL 5
#define NMEA_EXAMPLE "$GPGGA,064036.289,4836.5375,N,00740.9373,E,1,04,3.2,200.2,M,,,,0000*0E"
#define NMEA_INSERT_TIME(str_heure, time, temp, index) str_heure = str_insert(str_heure, trame.hour.##time < 10 ? str_concat("0", temp) : temp, index)

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
*  Nom du fichier : nmea.h                                                    *
*                                                                             *
******************************************************************************/

typedef struct
{
	float coord;
	char direction;
} coordinates;

typedef struct
{
	unsigned short hour;
	unsigned short minute;
	unsigned short second;
} hour;

typedef struct
{
	hour hour;
	coordinates longitude;
	coordinates latitude;
	unsigned short fix_qualification;
	unsigned short n_satellites_following;
	// dilution of precision
	float dop;
	// in meters
	float altitude;
	// ignore this field: it's a constant (M)
	//in meters
	float correction;
	// ignore this field: it's a constant (M)
	int elapsed_seconds_since_last_update;
	unsigned int dgps_id;
	// for next field, ignore star (just for dissplay purposes)
	int checksum;
} NMEA;

enum type_coord {LATITUDE , LONGITUDE , ALTITUDE };

short validate(char*);
NMEA str_to_nmea(char*);
char* nmea_get_heure(NMEA trame);
char* nmea_get_latitude(NMEA trame);
char* nmea_get_longitude(NMEA trame);
char* nmea_get_altitude(NMEA trame);
char* nmea_get_coord(NMEA trame,  enum type_coord tc);

#endif