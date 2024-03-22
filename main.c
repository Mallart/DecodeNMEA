#include "nmea.h"
#include <stdio.h>

void main(char** argv, int argc)
{
	char* trame_string;
	trame_string = argv[1] ? argv[1] : scanf("%s");
	NMEA trame = str_to_nmea(trame_string);
	printf("\n%dh", trame.hour.hour);
	printf("%dm", trame.hour.minute);
	printf("%ds\n", trame.hour.second);
}