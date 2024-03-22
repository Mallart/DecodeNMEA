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
    nmea_hour.hour = CAST_STR_TO_INT(str_copy(nmea_properties[0], 2));
    nmea_hour.minute = CAST_STR_TO_INT(str_copy(nmea_properties[0] + 2, 2));
    nmea_hour.second = CAST_STR_TO_INT(str_copy(nmea_properties[0] + 4, 2));
    temp_coordinates.coord = CAST_STR_TO_FLOAT(nmea_properties[1]);
    temp_coordinates.direction = nmea_properties[2][0];
    nmea.latitude = temp_coordinates;
    temp_coordinates.coord = CAST_STR_TO_FLOAT(nmea_properties[3]);
    temp_coordinates.direction = nmea_properties[4][0];
    nmea.longitude = temp_coordinates;
    nmea.fix_qualification = CAST_STR_TO_INT(nmea_properties[5]);
    nmea.n_satellites_following = CAST_STR_TO_INT(nmea_properties[6]);
    nmea.dop = CAST_STR_TO_FLOAT(nmea_properties[6]);
    nmea.altitude = CAST_STR_TO_FLOAT(nmea_properties[7]);
    nmea.correction = CAST_STR_TO_FLOAT(nmea_properties[8]);
    nmea.elapsed_seconds_since_last_update = CAST_STR_TO_INT(nmea_properties[9]);
    nmea.dgps_id = (unsigned)CAST_STR_TO_INT(nmea_properties[10]);
    nmea.checksum = CAST_STR_TO_INT(nmea_properties[10]);
    return nmea;
}
