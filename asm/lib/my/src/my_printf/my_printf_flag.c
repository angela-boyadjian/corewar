/*
** EPITECH PROJECT, 2017
** my_printf_flag.c
** File description:
** print each flag printf
*/

#include "my_printf.h"

int my_printf_s(va_list arg, char *args)
{
	int	i = 0;
	char const	*str = va_arg(arg, char const *);

	if (str == NULL) {
		my_putstr("(null)");
		return (0);
	}
	while (str[i] != '\0') {
		if (args != 0 && *args == 'l') {
			write(1, &str[i], 1);
			i += sizeof(int);
		} else {
			my_putchar(str[i++]);
		}
	}
	return (0);
}

int my_printf_bs(va_list arg, char *args)
{
	int	i = 0;
	int	count = 0;
	char const	*str = va_arg(arg, char const *);

	while (str[i] != '\0') {
		if (str[i] < 32 || str[i] >= 127) {
			my_putchar('\\');
			count += my_printf_bs_padding(str[i]);
			my_putnbr_base(str[i++], "01234567");
		} else {
			my_putchar(str[i++]);
		}
		count++;
	}
	args++;
	return (count);
}

int my_printf_i(va_list arg, char *args)
{
	int	str = va_arg(arg, int);
	int	padding = 0;

	padding = my_printf_d_padding(str, args);
	my_put_nbr(str);
	return (padding + number_len(str));
}

int my_printf_c(va_list arg, char *args)
{
	int	str = va_arg(arg, int);

	my_putchar(str);
	args++;
	return (1);
}

int my_printf_d(va_list arg, char *args)
{
	int	str = va_arg(arg, int);
	int	padding = 0;

	padding = my_printf_d_padding(str, args);
	if (args != 0 && *args == ' ')
		my_putchar(' ');
	my_put_nbr(str);
	return (padding + number_len(str));
}
