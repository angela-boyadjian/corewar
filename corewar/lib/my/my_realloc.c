/*
** EPITECH PROJECT, 2017
** my_realloc.c
** File description:
** my_realloc
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *my_realloc(char *str)
{
	static int	size = 1020;
	char		*tmp;

	if (my_strlen(str) == size) {
		size = size * 2;
		tmp = malloc(sizeof(char) * size);
		for (int i = 0; i < my_strlen(str); ++i)
			tmp[i] = str[i];
		free(str);
		return (tmp);
	}
	return (str);
}
