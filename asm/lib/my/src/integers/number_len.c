/*
** EPITECH PROJECT, 2017
** number_len.c
** File description:
** get length of a number
*/

#include "my.h"

int number_len(int nb)
{
	int	len = 0;
	int	n;

	if (nb == 0)
		return (1);
	n = nb;
	while (n != 0) {
		n /= 10;
		len++;
	}
	return (len);
}
