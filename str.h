// This file is under MIT License and is written by Matheo Allart. Its source is:
// https://github.com/Mallart/string2

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
*  Nom du fichier : str.h                                                     *
*                                                                             *
******************************************************************************/

// multi-includes prevention
#ifndef STR2
#define STR2

#include <stdlib.h>

#define bool unsigned short
#define CHECK_PTR(ptr) if(!ptr) return 0
#define CAST_STR_TO_INT(str) str_to_int(str, str_len(str))
#define CAST_STR_TO_FLOAT(str) str_to_float(str, str_len(str))

// Renvoie le nombre d'elements dans un tableau de pointeurs.
int ptr_array_len(void** _array);
// Compte les occurrences de caracteres dans une chaîne de caracteres.
int str_count_char(char* str, char c);
// Renvoie le nombre de caracteres dans une chaîne de caracteres terminee par un caractere nul.
short str_len(char* string);
// Renvoie une nouvelle chaîne identique a celle fournie.
char* str_copy(char* string, int length_to_copy);
// Renvoie la position du caractere donne dans la chaîne, ou la longueur de la chaîne si ce caractere n'est pas present.
int str_indexof(char* string, char character);
// Renvoie 1 si les deux chaînes sont identiques, 0 sinon.
bool str_compare(char* string_1, char* string_2, int length);
// Renvoie un tableau de chaînes, separees par un caractere supprime a la fin du traitement.
char** str_split(char* string, char delimiter);
// Convertit une chaîne en un entier.
int str_to_int(char* string, int length);
// Convertit une chaîne en un nombre a virgule flottante.
// La partie flottante ignore tout texte present dans la chaîne qui n'est pas constitue de chiffres.
float str_to_float(char* str, int length);
// Supprime les tabulations, les retours a la ligne et les espaces avant le premier caractere visible et apres le dernier.
char* str_trim(char* string);
// Cree une nouvelle chaîne basee sur celle donnee, mais commençant a un index donne et se terminant n caracteres apres.
char* str_substring(char* string, int start, int length);
// Retourne une nouvelle chaine de caracteres basee sur l'initiale, mais commencant a un index donne et finissant a index + longueur.
char* str_concat(char* str1, char* str2);
// Insere une nouvelle chaine de caracteres dans celle donnee a l'index fourni 
char* str_insert(char* str, char* insert, int index);
// Convtit un int vers une string
char* int_to_str(long long n);
// Convertit un float vers une string
char* float_to_str(float n);

int num_zeros(long long n);
int f_num_zeros(float n);
int power(int a, int b);
float inverse_power(float, float);

#endif