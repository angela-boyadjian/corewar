/*
** EPITECH PROJECT, 2017
** my_strcapitalize.c
** File description:
** capitalize the words in str
*/

#include "my.h"

static void reset_chars(char *str)
{
	int	i = 0;

	while (*(str + i) != '\0') {
		if (*(str + i) <= 'Z' && *(str + i) >= 'A')
			*(str + i) += 32;
		++i;
	}
}

static void set_upcase(char *str, int *i)
{
	if (*(str + *i) >= 'a' && *(str + *i) <= 'z') {
		*(str + *i) -= 32;
		*i += 1;
	}
}

char *my_strcapitalize(char *str)
{
	int	i = 0;

	reset_chars(str);
	if (*(str + i) >= 'a' && *(str + i) <= 'z')
		*(str + i) -= 32;
	while (*(str + i) != '\0') {
		if (*(str + i) == ' ' || *(str + i) == '-' ||
				*(str + i) == '+') {
			i += 1;
			set_upcase(str, &i);
		} else {
			i += 1;
		}
	}
	return (str);
}
