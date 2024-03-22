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

// Renvoie le nombre d'éléments dans un tableau de pointeurs.
int ptr_array_len(void** _array);
// Compte les occurrences de caractères dans une chaîne de caractères.
int str_count_char(char* str, char c);
// Renvoie le nombre de caractères dans une chaîne de caractères terminée par un caractère nul.
short str_len(char* string);
// Renvoie une nouvelle chaîne identique à celle fournie.
char* str_copy(char* string, int length_to_copy);
// Renvoie la position du caractère donné dans la chaîne, ou la longueur de la chaîne si ce caractère n'est pas présent.
int str_indexof(char* string, char character);
// Renvoie 1 si les deux chaînes sont identiques, 0 sinon.
bool str_compare(char* string_1, char* string_2, int length);
// Renvoie un tableau de chaînes, séparées par un caractère supprimé à la fin du traitement.
char** str_split(char* string, char delimiter);
// Convertit une chaîne en un entier.
int str_to_int(char* string, int length);
// Convertit une chaîne en un nombre à virgule flottante.
// La partie flottante ignore tout texte présent dans la chaîne qui n'est pas constitué de chiffres.
float str_to_float(char* str, int length);
// Supprime les tabulations, les retours à la ligne et les espaces avant le premier caractère visible et après le dernier.
char* str_trim(char* string);
// Crée une nouvelle chaîne basée sur celle donnée, mais commençant à un index donné et se terminant n caractères après.
char* str_substring(char* string, int start, int length);

int power(int a, int b);
float inverse_power(float, float);

#endif