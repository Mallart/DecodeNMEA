#pragma warning(disable:4996)
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
*  Nom du fichier : str.h                                                     *
*                                                                             *
******************************************************************************/

// multi-includes prevention
#ifndef STR2
#define STR2

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define bool unsigned short
#define APPEND_STR(_dest, _src) memcpy(_dest, _src, strlen(_src) * sizeof(char))
#define APPEND_INCR_STR(_index, _dest, _src) { memcpy(_dest + _index, _src, strlen(_src) * sizeof(char)); _index += strlen(_src); }
#define STR_INCR_RETURN(_index, _dest) { memcpy(_dest + index, "\n", 1); _index++; }
#define CHECK_PTR(ptr) if(!ptr) return
// Non void
#define CHECK_NV_PTR(ptr) if(!ptr) return 0
#define CAST_STR_TO_INT(str) atoi(str)
#define CAST_STR_TO_FLOAT(str) atof(str);
// Renvoie le nombre d'elements dans un tableau de pointeurs.
int ptr_array_len(void** _array);
// Compte les occurrences de caracteres dans une cha�ne de caracteres.
int str_count_char(char* str, char c);
// Renvoie une nouvelle cha�ne identique a celle fournie.
char* str_copy(char* string, int length_to_copy);
// Renvoie la position du caractere donne dans la cha�ne, ou la longueur de la cha�ne si ce caractere n'est pas present.
int str_indexof(char* string, char character);
// Renvoie 1 si les deux cha�nes sont identiques, 0 sinon.
bool str_compare(char* string_1, char* string_2, int length);
// Renvoie un tableau de cha�nes, separees par un caractere supprime a la fin du traitement.
char** str_split(char* string, char delimiter);
// Convertit une cha�ne en un entier.
int str_to_int(char* string, int length);
// Convertit une cha�ne en un nombre a virgule flottante.
// La partie flottante ignore tout texte present dans la cha�ne qui n'est pas constitue de chiffres.
float str_to_float(char* str, int length);
// Supprime les tabulations, les retours a la ligne et les espaces avant le premier caractere visible et apres le dernier.
char* str_trim(char* string);
// Cree une nouvelle cha�ne basee sur celle donnee, mais commen�ant a un index donne et se terminant n caracteres apres.
char* str_substring(char* string, int start, int length);
// Retourne une nouvelle chaine de caracteres basee sur l'initiale, mais commencant a un index donne et finissant a index + longueur.
char* str_concat(char* str1, char* str2);
// Insere une nouvelle chaine de caracteres dans celle donnee a l'index fourni 
char* str_insert(char* str, char* insert, int index);
// Convertit un int vers une string
char* int_to_str(long long n);
// Convertit un float vers une string
char* float_to_str(float n);
// Convertit un caractere vers une string
char* char_to_str(char c);
// Trouve un caractere et retourne sa position
size_t find_char(char* str, char c);

int num_zeros(long long n);
int f_num_zeros(float n);
int power(int a, int b);
float inverse_power(float, float);

#endif