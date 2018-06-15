/*
** EPITECH PROJECT, 2017
** dupstr.c
** File description:
** allocate given string to memory.
*/

#include "clist.h"

char *dupstr(char const *src, int pos)
{
	char	*str;
	int	i = 0;

	if (src == 0)
		return (0);
	str = (char *)malloc(sizeof(char) * (len(src) + 1));
	while (src[i] != '\0' && i < pos) {
		str[i] = src[i];
		++i;
	}
	str[i] = '\0';
	return (str);
}
