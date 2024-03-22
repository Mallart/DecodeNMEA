#include "nmea.h"
#include <stdio.h>
#define BUFFER_LENGTH 2048

void main(char** argv, int argc)
{
	char trame_string[BUFFER_LENGTH];
	if(argc < 2)
		fgets(trame_string, BUFFER_LENGTH, stdin);
	NMEA trame = str_to_nmea(argc < 2 ? argv[1] : trame_string);
	printf("\n%dh", trame.hour.hour);
	printf("%dm", trame.hour.minute);
	printf("%ds\n", trame.hour.second);
}