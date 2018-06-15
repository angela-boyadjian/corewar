/*
** EPITECH PROJECT, 2017
** my_strncat
** File description:
** concat a string on n bites
*/

#include "my.h"

char *my_strncat(char *dest, char const *src, int n)
{
	int	i = 0;
	int	c = 0;

	while (*(dest + c) != '\0')
		c++;
	while (*(src + i) != '\0' && i < n) {
		*(dest + (c + i)) = *(src + i);
		++i;
	}
	return (dest);
}
