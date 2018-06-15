/*
** EPITECH PROJECT, 2017
** get_digit.c
** File description:
** get a digit from its location
*/

#include "my.h"

int get_digit(int nb, int loc)
{
	int	size;
	int	i = 0;

	if (nb == 0)
		return (0);
	size = number_len(nb) - (loc + 1);
	while (i++ < size)
		nb /= 10;
	return (nb % 10);
}
