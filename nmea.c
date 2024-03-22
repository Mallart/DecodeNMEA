#include "nmea.h"

short validate(char* nmea)
{
    return str_compare(NMEA_START, nmea, 6);
}

NMEA str_to_nmea(char* str)
{
    NMEA nmea;
    hour nmea_hour;
    coordinates temp_coordinates;
    char** nmea_properties = str_split(str, ',');
    nmea_hour.hour = CAST_STR_TO_INT(str_copy(nmea_properties[1], 2));
    nmea_hour.minute = CAST_STR_TO_INT(str_copy(nmea_properties[1] + 2, 2));
    nmea_hour.second = CAST_STR_TO_INT(str_copy(nmea_properties[1] + 4, 2));
    nmea.hour = nmea_hour;
    temp_coordinates.coord = CAST_STR_TO_FLOAT(nmea_properties[2]);
    temp_coordinates.direction = nmea_properties[3][0];
    nmea.latitude = temp_coordinates;
    temp_coordinates.coord = CAST_STR_TO_FLOAT(nmea_properties[4]);
    temp_coordinates.direction = nmea_properties[5][0];
    nmea.longitude = temp_coordinates;
    nmea.fix_qualification = CAST_STR_TO_INT(nmea_properties[6]);
    nmea.n_satellites_following = CAST_STR_TO_INT(nmea_properties[7]);
    nmea.dop = CAST_STR_TO_FLOAT(nmea_properties[8]);
    nmea.altitude = CAST_STR_TO_FLOAT(nmea_properties[9]);
    nmea.correction = CAST_STR_TO_FLOAT(nmea_properties[10]);
    nmea.elapsed_seconds_since_last_update = CAST_STR_TO_INT(nmea_properties[11]);
    nmea.dgps_id = (unsigned)CAST_STR_TO_INT(nmea_properties[12]);
    nmea.checksum = CAST_STR_TO_INT(nmea_properties[13]);
    return nmea;
}

char* nmea_get_heure(NMEA trame)
{
    char* str_heure = malloc(sizeof(char)* 10); 
    str_heure[0] = int_to_str(trame.hour.hour);
    str_heure[2] = 'h';
    str_heure[3] = int_to_str(trame.hour.minute);
    str_heure[5] = 'm';
    str_heure[6] = int_to_str(trame.hour.second);
    str_heure[8] = 's';
    str_heure[9] = '\0';
    return str_heure;
}

char* nmea_get_latitude(NMEA trame)
{
    char* str_latitude = malloc(sizeof(char)* (str_len(float_to_str(trame.latitude.coord)) + 2)); 
    str_latitude[0] = float_to_str(trame.latitude.coord);
    str_latitude[str_len(float_to_str(trame.latitude.coord))] = trame.latitude.direction;
    str_latitude[str_len(float_to_str(trame.latitude.coord)) + 1] = '\0';
    return str_latitude;
}

char* nmea_get_longitude(NMEA trame)
{
    char* str_longitude = malloc(sizeof(char)* (str_len(float_to_str(trame.longitude.coord)) + 2));
    str_longitude[0] = float_to_str(trame.longitude.coord);
    str_longitude[str_len(float_to_str(trame.longitude.coord))] = trame.longitude.direction;
    str_longitude[str_len(float_to_str(trame.longitude.coord)) + 1] = '\0';
    return str_longitude;
}

char* nmea_get_altitude(NMEA trame)
{
    char* str_altitude = malloc(sizeof(char)* (str_len(float_to_str(trame.altitude)) + 2)); 
    str_altitude[0] = float_to_str(trame.altitude);
    str_altitude[str_len(float_to_str(trame.altitude))] = 'M\0';
    return str_altitude;
}

char* nmea_get_coord(NMEA trame, enum type_coord tc)
{
    if (tc & LATITUDE)
    {
        return nmea_get_latitude(trame);
    }
    if (tc & LONGITUDE)
    {
        return nmea_get_longitude(trame);
    }
    if (tc & ALTITUDE)
    {
        return nmea_get_altitude(trame);
    }

}