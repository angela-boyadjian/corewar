/*
** EPITECH PROJECT, 2017
** my_strcpy.c
** File description:
** function to copy string
*/

#include "my.h"

char *my_strcpy(char *dest, char const *src)
{
	int	i = 0;

	if (dest == 0 || src == 0)
		return (0);
	while (*src != '\0')
		*(dest + i++) = *src++;
	*(dest + i) = '\0';
	return (dest);
}
