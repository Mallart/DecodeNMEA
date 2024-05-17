#include "nmea.h"

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
*  Nom du fichier : nmea.c                                                    *
*                                                                             *
******************************************************************************/

short validate(char* nmea)
{
	return str_compare(NMEA_START, nmea, 6);
}

NMEA str_to_nmea(char* str)
{
	NMEA nmea;
	hour nmea_hour;
	coordinates* temp_coordinates = malloc(sizeof(coordinates));
	char** nmea_properties = str_split(str, ',');
	nmea_hour.hour = CAST_STR_TO_INT(str_copy(nmea_properties[1], 2));
	nmea_hour.minute = CAST_STR_TO_INT(str_copy(nmea_properties[1] + 2, 2));
	nmea_hour.second = CAST_STR_TO_INT(str_copy(nmea_properties[1] + 4, 2));
	nmea.hour = nmea_hour;
	temp_coordinates->coord = CAST_STR_TO_FLOAT(nmea_properties[2]);
	temp_coordinates->direction = nmea_properties[3][0];
	nmea.latitude = *temp_coordinates;
	temp_coordinates->coord = CAST_STR_TO_FLOAT(nmea_properties[4]);
	temp_coordinates->direction = nmea_properties[5][0];
	nmea.longitude = *temp_coordinates;
	nmea.fix_qualification = CAST_STR_TO_INT(nmea_properties[6]);
	nmea.n_satellites_following = CAST_STR_TO_INT(nmea_properties[7]);
	nmea.dop = CAST_STR_TO_FLOAT(nmea_properties[8]);
	nmea.altitude = CAST_STR_TO_FLOAT(nmea_properties[9]);
	// nmea_properties[10] is char and altitude's unit
	nmea.correction = CAST_STR_TO_FLOAT(nmea_properties[11]);
	// nmea_properties[12] is char and correction's unit
	nmea.elapsed_seconds_since_last_update = CAST_STR_TO_INT(nmea_properties[12]);
	nmea.dgps_id = (unsigned)CAST_STR_TO_INT(nmea_properties[13]);
	nmea.checksum = CAST_STR_TO_INT(nmea_properties[14]);
	return nmea;
}

char* nmea_get_heure(NMEA trame)
{
	char* temp = "  ";
	CHECK_NV_PTR(temp);
	char* str_heure = malloc(sizeof(char) * 10);
	CHECK_NV_PTR(str_heure);
	NMEA_INSERT_TIME(str_heure, trame.hour.hour, int_to_str(trame.hour.hour % 24), 0);
	str_heure[2] = 'h';
	NMEA_INSERT_TIME(str_heure, trame.hour.minute, int_to_str(trame.hour.minute % 60), 3);
	str_heure[5] = 'm';
	NMEA_INSERT_TIME(str_heure, trame.hour.second, int_to_str(trame.hour.second % 60), 6);
	str_heure[8] = 's';
	str_heure[9] = '\0';
	return str_trim(str_heure);
}

char* nmea_get_raw_heure(NMEA trame)
{
	char* str_heure = malloc(sizeof(char) * 6);
	CHECK_NV_PTR(str_heure);
	NMEA_INSERT_TIME(str_heure, trame.hour.hour, int_to_str(trame.hour.hour % 24), 0);
	NMEA_INSERT_TIME(str_heure, trame.hour.minute, int_to_str(trame.hour.minute % 60), 2);
	NMEA_INSERT_TIME(str_heure, trame.hour.second, int_to_str(trame.hour.second % 60), 4);
	str_heure[6] = '\0';
	return str_heure;
}

char* nmea_get_latitude(NMEA trame)
{
	char* temp_str = float_to_str(trame.latitude.coord);
	int latitude_length = strlen(temp_str);
	char* str_latitude = malloc(sizeof(char) * (latitude_length + 2));
	CHECK_NV_PTR(str_latitude);
	str_latitude = str_insert(str_latitude, temp_str, 0);
	str_latitude[latitude_length] = trame.latitude.direction;
	str_latitude[latitude_length + 1] = '\0';
	return str_latitude;
}

char* nmea_get_longitude(NMEA trame)
{
	char* temp_str = float_to_str(trame.longitude.coord);
	int longitude_length = strlen(temp_str);
	char* str_longitude = malloc(sizeof(char) * (longitude_length + 2));
	CHECK_NV_PTR(str_longitude);
	str_longitude = str_insert(str_longitude, temp_str, 0);
	str_longitude[longitude_length] = trame.longitude.direction;
	str_longitude[longitude_length + 1] = '\0';
	return str_longitude;
}

char* nmea_get_altitude(NMEA trame)
{
	char* temp_str = float_to_str(trame.altitude);
	int altitude_length = strlen(temp_str);
	char* str_altitude = malloc(sizeof(char) * (altitude_length + 2));
	CHECK_NV_PTR(str_altitude);
	str_altitude = str_insert(str_altitude, temp_str, 0);
	str_altitude[altitude_length] = '\0';
	return str_altitude;
}

char* nmea_to_str(NMEA* nmea)
{
	return str_poly_concat(32,
		"$GPGGA", NMEA_RECORD_DELIMITER,
		nmea_get_raw_heure(*nmea), NMEA_RECORD_DELIMITER,
		float_to_str(nmea->latitude.coord), NMEA_RECORD_DELIMITER,
		char_to_str(nmea->latitude.direction), NMEA_RECORD_DELIMITER,
		float_to_str(nmea->longitude.coord), NMEA_RECORD_DELIMITER,
		char_to_str(nmea->longitude.direction), NMEA_RECORD_DELIMITER,
		int_to_str(nmea->fix_qualification), NMEA_RECORD_DELIMITER,
		int_to_str(nmea->n_satellites_following), NMEA_RECORD_DELIMITER,
		float_to_str(nmea->dop), NMEA_RECORD_DELIMITER,
		float_to_str(nmea->altitude), NMEA_RECORD_DELIMITER,
		"M", NMEA_RECORD_DELIMITER,
		float_to_str(nmea->correction), NMEA_RECORD_DELIMITER,
		"M", NMEA_RECORD_DELIMITER,
		int_to_str(nmea->elapsed_seconds_since_last_update), NMEA_RECORD_DELIMITER,
		int_to_str(nmea->dgps_id), NMEA_RECORD_DELIMITER,
		int_to_str(nmea->checksum), "\n"
	);
}

char* nmea_get_coord(NMEA trame, enum type_coord tc)
{
	if (tc == LATITUDE)
	{
		return nmea_get_latitude(trame);
	}
	if (tc == LONGITUDE)
	{
		return nmea_get_longitude(trame);
	}
	if (tc == ALTITUDE)
	{
		return nmea_get_altitude(trame);
	}

}