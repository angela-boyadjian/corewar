/*
** EPITECH PROJECT, 2017
** my_printf_padding.c
** File description:
** padding of 0 for my_printf
*/

#include "my_printf.h"

int my_printf_bs_padding(int no)
{
	if (no >= 0 && no <= 7) {
		my_putstr("00");
		return (2);
	}
	if (no >= 8 && no <= 63) {
		my_putchar('0');
		return (1);
	}
	return (0);
}

int my_printf_d_padding(int str, char *args)
{
	int	padding_no = 0;
	int	i = 0;

	if (args == 0)
		return (0);
	if (*args != '0')
		padding_no = my_getnbr(args);
	else
		padding_no = my_getnbr(args + 1);
	while (i < (padding_no - number_len(str))) {
		if (*args == '0')
			my_putchar(*args);
		else
			my_putchar(' ');
		++i;
	}
	return (i);
}
