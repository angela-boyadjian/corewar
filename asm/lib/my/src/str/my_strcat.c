/*
** EPITECH PROJECT, 2017
** my_strcat.c
** File description:
** concat strings
*/
#include "my.h"

char	*my_strcat(char *dest, char const *src)
{
	int	i = 0;
	int	dest_size = 0;

	while (dest[dest_size])
		dest_size++;
	while (src[i]) {
		dest[dest_size] = src[i];
		dest_size++;
		i++;
	}
	dest[dest_size] = '\0';
	return (dest);
}