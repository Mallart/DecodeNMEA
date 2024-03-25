#pragma once
#include <stdio.h>
#include "nmea.h"
#include "estr.h"
#define NMEA_RECORD_DELIMITER ","

/******************************************************************************
*  ASR => 4R2.04                                                              *
*******************************************************************************
*                                                                             *
*  N� de Sujet : 01                                                           *
*                                                                             *
*******************************************************************************
*                                                                             *
*  Intitul� : Analyse de trame GPS                                            *
*                                                                             *
*******************************************************************************
*                                                                             *
*  Nom-pr�nom1 : Allart Math�o                                                *
*                                                                             *
*  Nom-pr�nom2 : Vallette No�                                                 *
*                                                                             *
*  Nom-pr�nom3 :                                                              *
*                                                                             *
*  Nom-pr�nom4 :                                                              *
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
