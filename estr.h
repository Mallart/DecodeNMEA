#ifndef NMEA_ESTR
#define NMEA_ESTR

// ETENDU STR
#include <stdarg.h>
#include "str.h"

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
*  Nom du fichier : estr.h.c                                                    *
*                                                                             *
******************************************************************************/

// Concatene et renvoie plusieurs chaines de caracteres
char* str_poly_concat(int n_args, ...);
#endif