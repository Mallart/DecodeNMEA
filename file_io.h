// multi includes prevention
#ifndef NMEA_FILE_IO
#define NMEA_FILE_IO


#include <stdio.h>
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
*  Nom du fichier : file_io.h                                                 *
*                                                                             *
******************************************************************************/

// Enregistre toutes les donnees NMEA dans un fichier texte lisible.
void log_nmea(char* file_path, NMEA* nmea);
// Lit un fichier texte stockant une trame NMEA pour la retourner serialisee
NMEA* read_nmea(char* file_path);
// Serialise le contenu d'un flux vers une trame NMEA.
NMEA* parse_nmea(FILE* stream);

#endif