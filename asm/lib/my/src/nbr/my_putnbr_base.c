/*
** EPITECH PROJECT, 2017
** my_putnbr_base.c
** File description:
** function that prints a number from its base
*/

#include "my.h"

static int pnb_bas_nolen(char const *base)
{
	int	len = 0;

	while (*(base + len) != '\0')
		len++;
	return (len);
}

int my_putnbr_base(int nbr, char const *base)
{
	int	nb_len = pnb_bas_nolen(base);
	int	pos = 0;

	if (nbr < 0) {
		my_putchar('-');
		nbr *= -1;
	}
	if (base == 0)
		return (0);
	pos = nbr % nb_len;
	if (nbr > 0) {
		my_putnbr_base(nbr / nb_len, base);
		my_putchar(*(base + pos));
	}
	return (0);
}