#include "str.h"

int ptr_array_len(void** _array)
{
	CHECK_PTR(_array);
	int i = 0;
	for (; _array[i]; ++i);
	return i - 2;
}

int str_count_char(char* str, char c)
{
	CHECK_PTR(str);
	int occurences = 0;
	int length = str_len(str);
	for (int i = 0; i < length; ++i)
		occurences = str[i] == c ? ++occurences : occurences;
	return occurences;
}

short str_len(char* str)
{
	CHECK_PTR(str);
	int i = 0;
	for (; str[i]; ++i);
	return i;
}

char* str_copy(char* str, int len)
{
	char* output = malloc(sizeof(char*) * (len + 1));
	CHECK_PTR(output);
	for (int i = 0; i < len; ++i)
		output[i] = str[i];
	output[len] = '\0';
	return output;
}

int str_indexof(char* str, char c)
{
	int len = str_len(str);
	int i = 0;
	for (; i < len && str[i] != c; ++i);
	return i;
}

bool str_compare(char* str1, char* str2, int length)
{
	CHECK_PTR(str1);
	CHECK_PTR(str2);
	int i = 0;
	for (; i < length && str1[i] == str2[i]; ++i);
	return i == length;
}

char** str_split(char* str, char delimiter)
{
	int index = 0;
	int n_char = str_count_char(str, delimiter);
	if (!n_char)
		return str;
	CHECK_PTR(str);
	char** table = malloc(sizeof(char*) * n_char);
	CHECK_PTR(table);
	for (int i = 0; i < str_count_char(str, delimiter) + 1 && str[i]; ++i)
	{
		table[i] = str_copy(str + index, str_indexof(str + index, delimiter));
		index += str_indexof(str + index, delimiter) + 1;
	}
	return table;
}

int str_to_int(char* str, int len)
{
	int offset = 0;
	int sum = 0;
	int i = len;
	for (; i > 0; --i)
		if (str[i - 1 + offset] > 47 && str[i - 1 + offset] < 57)
			sum += (str[i - 1 + offset] - 48) * power(10, len - i);
		else
		{
			++offset;
			--i;
		}
	return sum;
}


float str_to_float(char* str, int len)
{
	int offset = 0;
	float sum = 0;
	int dot = str_indexof(str, '.');
	sum += str_to_int(str, dot);
	for (int i = dot + 1; str[i] && i + offset < len; ++i)
		if (str[i] > 47 && str[i] < 57)
			sum += (float)(str[i] - 48) / power(10, i + offset - dot);
		else
			--offset;
	return sum;
}

char* str_trim(char* str)
{
	int len = str_len(str);
	int index = 0;
	char* result = malloc(sizeof(char) * (
		len
		- str_count_char(str, ' ')
		- str_count_char(str, '\t')
		- str_count_char(str, '\n'))
	);
	CHECK_PTR(str);
	CHECK_PTR(result);
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
	CHECK_PTR(str);
	char* result = malloc(sizeof(char) * (length + 1));
	CHECK_PTR(result);
	for (int i = 0; str[i] && i < length; ++i)
		result[i] = str[i + start];
	result[length] = '\0';
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
