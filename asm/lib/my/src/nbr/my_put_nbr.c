/*
** EPITECH PROJECT, 2017
** my_put_nbr.c
** File description:
** print a number
*/

#include "my.h"

int my_put_nbr(int nb)
{
	if (nb <= 2147483647 && nb != -2147483648) {
		if (nb < 0) {
			my_putchar('-');
			nb *= -1;
		}
		if (nb > 9) {
			my_put_nbr(nb / 10);
			my_put_nbr(nb % 10);
		}
		if (nb >= 0 && nb <= 9)
			my_putchar(nb + '0');
	}
	return (0);
}
