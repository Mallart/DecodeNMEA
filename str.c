#include "str.h"

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
*  Nom du fichier : str.c                                                     *
*                                                                             *
******************************************************************************/

int ptr_array_len(void** _array)
{
	CHECK_NV_PTR(_array);
	int i = 0;
	for (; _array[i]; ++i);
	return i - 2;
}

int str_count_char(char* str, char c)
{
	CHECK_NV_PTR(str);
	int occurences = 0;
	int length = strlen(str);
	for (int i = 0; i < length; ++i)
		occurences = str[i] == c ? ++occurences : occurences;
	return occurences;
}

char* str_copy(char* str, int len)
{
	char* output = malloc(sizeof(char*) * (len + 1));
	CHECK_NV_PTR(output);
	memcpy(output, str, len);
	return output;
}

int str_indexof(char* str, char c)
{
	int len = strlen(str);
	int i = 0;
	for (; i < len && str[i] != c; ++i);
	return i;
}

bool str_compare(char* str1, char* str2, int length)
{
	CHECK_NV_PTR(str1);
	CHECK_NV_PTR(str2);
	int i = 0;
	for (; i < length && str1[i] == str2[i]; ++i);
	return i == length;
}

char** str_split(char* str, char delimiter)
{
	int index = 0;
	int n_char = str_count_char(str, delimiter);
	CHECK_NV_PTR(str);
	char** table;
	if (!n_char)
	{
		table = malloc(sizeof(char*));
		CHECK_NV_PTR(table);
		table[0] = str;
		return table;
	}
	table = malloc(sizeof(char*) * n_char);
	CHECK_NV_PTR(table);
	for (int i = 0; i < str_count_char(str, delimiter) + 1 && str[i]; ++i)
	{
		table[i] = str_copy(str + index, str_indexof(str + index, delimiter));
		index += str_indexof(str + index, delimiter) + 1;
	}
	return table;
}

int str_to_int(char* str, int len)
{
	return atoi(str);
	int offset = 0;
	int sum = 0;
	int i = len;
	for (; i > 0; --i)
		if (str[i - 1 + offset] > 47 && str[i - 1 + offset] < 58)
			sum += (str[i - 1 + offset] - 48) * power(10, len - i);
		else
		{
			++offset;
			--i;
		}
	return sum;
}

char* int_to_str(long long n)
{
	int initial = n;
	int index = num_zeros(initial);
	char* str = malloc(sizeof(char) * (index + 2));
	CHECK_NV_PTR(str);
	while (index && n / index > 10)
	{
		str[index] = n % 10 + 48;
		n /= 10;
		--index;
	}
	str[0] = n %10 + 48 ;
	str[num_zeros(initial) + 1] = '\0';
	return str;
}

char* float_to_str(float n)
{
	return str_insert(int_to_str((long long)(n * power(10, f_num_zeros(n) + 1))), ".", f_num_zeros(n) + 1);
}

char* char_to_str(char c)
{
	char* str = malloc(sizeof(char) * 2);
	CHECK_NV_PTR(str);
	str[0] = c;
	str[1] = '\0';
	return str;
}

size_t find_char(char* str, char c)
{
	size_t i = 0;
	for (; i < strlen(str) && str[i] != c; ++i);
	return i;
}


float str_to_float(char* str, int len)
{
	return strtof(str, (char**)(unsigned long long)len);
}

char* str_trim(char* str)
{
	int len = strlen(str);
	int index = 0;
	char* result = malloc(sizeof(char) * (
		len
		- str_count_char(str, ' ')
		- str_count_char(str, '\t')
		- str_count_char(str, '\n'))
	);
	CHECK_NV_PTR(str);
	CHECK_NV_PTR(result);
	for (int i = 0; i < len; ++i)
	{
		switch (str[i])
		{
		case ' ':
		case '\t':
		case '\n': ++i;
		default:
			result[index] = str[i];
			++index;
			break;
		}
	}
	result[index] = '\0';
	return result;
}

char* str_substring(char* str, int start, int length)
{
	CHECK_NV_PTR(str);
	char* result = malloc(sizeof(char) * (length + 1));
	CHECK_NV_PTR(result);
	for (int i = 0; str[i] && i < length; ++i)
		result[i] = str[i + start];
	result[length] = '\0';
	return result;
}

char* str_concat(char* str1, char* str2)
{
	char* str = malloc(sizeof(char) * (strlen(str1) + strlen(str2)));
	CHECK_NV_PTR(str1);
	CHECK_NV_PTR(str2);
	CHECK_NV_PTR(str);
	memcpy(str, str1, strlen(str1));
	memcpy(str + strlen(str1), str2, strlen(str2));
	memcpy(str + strlen(str1) + strlen(str2), "\0", 1);
	return str;
}

char* str_insert(char* str, char* insert, int index)
{
	CHECK_NV_PTR(str);
	CHECK_NV_PTR(insert);
	int len = strlen(str);
	int insert_len = strlen(insert);
	char* result = malloc(sizeof(char) * (len + insert_len + 1));
	CHECK_NV_PTR(result);
	for (int i = len; i >= index; --i)
		result[i + insert_len] = str[i];
	for (int i = index; i < index + insert_len; ++i)
		result[i] = insert[i - index];
	for (int i = 0; i < index; ++i)
		result[i] = str[i];
	result[len + insert_len] = '\0';
	return result;
}

int power(int a, int b)
{
	int n = a;
	if (!b)
		return 1;
	for (int i = 1; i < b; ++i)
		n *= a;
	return n;
}

float inverse_power(float n, float p)
{
	return 1 / power(n, p);
}

int num_zeros(long long n)
{
	int i = 0;
	int f = (float)n;
	while (f > 10)
	{
		f /= 10;
		++i;
	}
	return i;
}

int f_num_zeros(float n)
{
	int i = 0;
	while (n > 10)
	{
		n /= 10;
		++i;
	}
	return i;
}