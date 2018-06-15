/*
** EPITECH PROJECT, 2017
** my_printf_usigned.c
** File description:
** unsigned function for my_printf
*/

#include "my_printf.h"

int my_printf_u(va_list arg, char *args)
{
	unsigned int	str = va_arg(arg, unsigned int);
	int	padding = 0;

	padding = my_printf_d_padding(str, args);
	my_put_nbr(str);
	return (padding + number_len(str));
}

int my_printf_o(va_list arg, char *args)
{
	int	padding = 0;
	unsigned int	str = va_arg(arg, unsigned int);

	if (args != 0 && *args == '#') {
		my_putstr("0");
		args++;
	}
	padding = my_printf_d_padding(str, args);
	if (str == 0)
		my_putchar('0');
	my_putnbr_base(str, "01234567");
	return (padding + number_len(str));
}

int my_printf_x(va_list arg, char *args)
{
	int	padding = 0;
	unsigned int	str = va_arg(arg, unsigned int);

	if (args != 0 && *args == '#') {
		my_putstr("0x");
		args++;
	}
	padding = my_printf_d_padding(str, args);
	if (str == 0)
		my_putchar('0');
	my_putnbr_base(str, "0123456789abcdef");
	return (padding + number_len(str));
}

int my_printf_bx(va_list arg, char *args)
{
	int	padding = 0;
	unsigned int	str = va_arg(arg, unsigned int);

	if (args != 0 && *args == '#') {
		my_putstr("0x");
		args++;
	}
	padding = my_printf_d_padding(str, args);
	if (str == 0)
		my_putchar('0');
	my_putnbr_base(str, "0123456789ABCDEF");
	return (padding + number_len(str));
}

int my_printf_b(va_list arg, char *args)
{
	int	padding = 0;
	int	str = va_arg(arg, int);

	if (str < 0) {
		my_putstr("1");
		str *= -1;
	}
	padding = my_printf_d_padding(str, args);
	if (str == 0)
		my_putchar('0');
	my_putnbr_base(str, "01");
	return (padding + number_len(str));
}
