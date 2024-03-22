#include "nmea.h"
#include <stdio.h>
#define BUFFER_LENGTH 2048

void main(int argc, char** argv)
{
	char trame_string[BUFFER_LENGTH + 1];
	if (argc < 2)
	{
		printf("\nVeuillez entrer une trame NMEA:\n");
		fgets(trame_string, BUFFER_LENGTH, stdin);
		trame_string[BUFFER_LENGTH] = '\0';
	}
	if (!validate(trame_string))
	{
		printf("La trame n'est pas valide.");
		exit(1);
	}
	NMEA* trame = str_to_nmea(argc > 2 ? argv[1] : trame_string);
	printf("\n%dh", trame->hour.hour);
	printf("%dm", trame->hour.minute);
	printf("%ds\n", trame->hour.second);
}

