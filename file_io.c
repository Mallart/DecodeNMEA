#include "file_io.h"

void log_nmea(char* file_path, NMEA* nmea)
{
	FILE* f;
	fopen_s(&f, file_path, "w+");
	if (!f)
		return;
	char* nmea_to_string = str_poly_concat(21,
		"$GPGGA",
		nmea_get_heure(*nmea),									NMEA_RECORD_DELIMITER,
		nmea_get_longitude(*nmea),								NMEA_RECORD_DELIMITER,
		nmea_get_latitude(*nmea),								NMEA_RECORD_DELIMITER,
		float_to_str(nmea->fix_qualification),					NMEA_RECORD_DELIMITER,
		float_to_str(nmea->dop),								NMEA_RECORD_DELIMITER,
		float_to_str(nmea->altitude),							NMEA_RECORD_DELIMITER,
		float_to_str(nmea->correction),							NMEA_RECORD_DELIMITER,
		int_to_str(nmea->elapsed_seconds_since_last_update),	NMEA_RECORD_DELIMITER,
		int_to_str(nmea->dgps_id),								NMEA_RECORD_DELIMITER,
		int_to_str(nmea->checksum), "\n"
	);
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
		fclose(f);
		return trame;
	}
	return;
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
