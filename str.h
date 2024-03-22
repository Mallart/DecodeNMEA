// This file is under MIT License and is written by Matheo Allart:
// https://github.com/Mallart/string2


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
// Compte les occurrences de caracteres dans une cha�ne de caracteres.
int str_count_char(char* str, char c);
// Renvoie le nombre de caracteres dans une cha�ne de caracteres terminee par un caractere nul.
short str_len(char* string);
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

int power(int a, int b);
float inverse_power(float, float);

#endif