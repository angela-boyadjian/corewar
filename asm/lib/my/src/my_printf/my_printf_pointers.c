/*
** EPITECH PROJECT, 2017
** my_printf_pointers.c
** File description:
** display the pointers in printf
*/

#include "my_printf.h"

static void my_putnbr_base_local(unsigned long nbr, char const *base)
{
	unsigned long	nb_len = 16;
	unsigned long	pos = 0;

	pos = nbr % nb_len;
	if (nbr > 0) {
		my_putnbr_base_local(nbr / nb_len, base);
		my_putchar(base[pos]);
	}
}

int my_printf_p(va_list arg, char *args)
{
	unsigned long	p = va_arg(arg, unsigned long);

	if (p != 0) {
		my_putstr("0x");
		my_putnbr_base_local(p, "0123456789abcdef");
	} else {
		my_putstr("(nil)");
	}
	args++;
	return (0);
}

int my_printf_n(va_list arg, char *args)
{
	int	*p = va_arg(arg, int *);

	*p = my_print_write_count;
	args++;
	return (0);
}
