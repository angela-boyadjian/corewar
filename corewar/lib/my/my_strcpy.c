/*
** EPITECH PROJECT, 2017
** my_strcpy.c
** File description:
** le_copy
*/

#include <unistd.h>

char *my_strcpy(char *dest, char *src)
{
	int	i = 0;

	while (src[i] != '\0') {
		dest[i] = src[i];
		++i;
	}
	dest[i] = '\0';
	return (dest);
}
