#pragma once
#include <stdio.h>
#include "nmea.h"
#include "estr.h"
#define NMEA_RECORD_DELIMITER ","

// Enregistre toutes les donnees NMEA dans un fichier texte lisible.
void log_nmea(char* file_path, NMEA* nmea);
// Lit un fichier texte stockant une trame NMEA pour la retourner serialisee
NMEA* read_nmea(char* file_path);
// Serialise le contenu d'un flux vers une trame NMEA.
NMEA* parse_nmea(FILE* stream);
