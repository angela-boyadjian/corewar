/*
** EPITECH PROJECT, 2017
** my_strndup
** File description:
** allocate given string to memory.
*/

#include "my.h"

char *my_strndup(char const *src, int size)
{
	char	*str;
	int	i = 0;

	if (src == 0)
		return (0);
	str = (char *)malloc(sizeof(char) * (my_strlen(src) + 1));
	while (src[i] != '\0' && i < size) {
		str[i] = src[i];
		++i;
	}
	str[i] = '\0';
	return (str);
}
