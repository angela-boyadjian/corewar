/*
** EPITECH PROJECT, 2017
** len.c
** File description:
** Return the size of str
*/

#include "clist.h"

int len(char const *str)
{
	int	len = 0;

	if (str == 0)
		return (-1);
	while (*str++ != '\0')
		len++;
	return (len);
}
