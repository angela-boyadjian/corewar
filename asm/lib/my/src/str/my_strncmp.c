/*
** EPITECH PROJECT, 2017
** my_strncmp.c
** File description:
** compare n bytes
*/
#include "my.h"

int my_strncmp(char const *s1, char const *s2, int n)
{
	int	i = 0;
	char	j;

	while (s1[i] == s2[i] && (s1[i] && s2[i]) && i < n)
		++i;
	j = s1[i] - s2[i];
	if (i == n)
		return (0);
	return (j);
}