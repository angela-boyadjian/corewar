/*
** EPITECH PROJECT, 2017
** my_strcmp.c
** File description:
** str compare
*/
#include "my.h"

int my_strcmp(char const *s1, char const *s2)
{
	int	i = 0;
	char	j;

	while (s1[i] == s2[i] && (s1[i] && s2[i]))
		++i;
	j = s1[i] - s2[i];
	return (j);
}