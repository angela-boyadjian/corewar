/*
** EPITECH PROJECT, 2017
** my_strdup
** File description:
** allocate given string to memory.
*/

#include "my.h"

char *my_strdup(char const *src)
{
	char	*str;
	int	i = 0;

	if (src == 0)
		return (0);
	str = (char *)malloc(sizeof(char) * (my_strlen(src) + 1));
	while (src[i] != '\0') {
		str[i] = src[i];
		++i;
	}
	str[i] = '\0';
	return (str);
}
