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

// Renvoie le nombre d'�l�ments dans un tableau de pointeurs.
int ptr_array_len(void** _array);
// Compte les occurrences de caract�res dans une cha�ne de caract�res.
int str_count_char(char* str, char c);
// Renvoie le nombre de caract�res dans une cha�ne de caract�res termin�e par un caract�re nul.
short str_len(char* string);
// Renvoie une nouvelle cha�ne identique � celle fournie.
char* str_copy(char* string, int length_to_copy);
// Renvoie la position du caract�re donn� dans la cha�ne, ou la longueur de la cha�ne si ce caract�re n'est pas pr�sent.
int str_indexof(char* string, char character);
// Renvoie 1 si les deux cha�nes sont identiques, 0 sinon.
bool str_compare(char* string_1, char* string_2, int length);
// Renvoie un tableau de cha�nes, s�par�es par un caract�re supprim� � la fin du traitement.
char** str_split(char* string, char delimiter);
// Convertit une cha�ne en un entier.
int str_to_int(char* string, int length);
// Convertit une cha�ne en un nombre � virgule flottante.
// La partie flottante ignore tout texte pr�sent dans la cha�ne qui n'est pas constitu� de chiffres.
float str_to_float(char* str, int length);
// Supprime les tabulations, les retours � la ligne et les espaces avant le premier caract�re visible et apr�s le dernier.
char* str_trim(char* string);
// Cr�e une nouvelle cha�ne bas�e sur celle donn�e, mais commen�ant � un index donn� et se terminant n caract�res apr�s.
char* str_substring(char* string, int start, int length);

int power(int a, int b);
float inverse_power(float, float);

#endif