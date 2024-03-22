#ifndef NMEA_START
#include "str.h"
#define NMEA_START "$GPGGA"
#define NMEA_MIN_N_FIELDS 15

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


short validate(char*);
NMEA* str_to_nmea(char*);
#endif