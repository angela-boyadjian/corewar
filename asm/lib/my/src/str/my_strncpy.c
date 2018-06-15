/*
** EPITECH PROJECT, 2017
** my_strncpy.c
** File description:
** copy string to destination.
*/

#include "my.h"

char *my_strncpy(char *dest, char const *src, int n)
{
	int	i = -1;

	while (*src != '\0' && ++i <= n)
		*(dest + i) = *src++;
	*(dest + i) = '\0';
	return (dest);
}
