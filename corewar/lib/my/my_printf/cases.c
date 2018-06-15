/*
** EPITECH PROJECT, 2017
** cases.c
** File description:
** Case s
*/

#include "../../../include/my.h"

int case_s(va_list ap)
{
	char	*str = va_arg(ap, char *);

	my_putstr(str);
	return (0);
}

int case_d(va_list ap)
{
	int	nb = va_arg(ap, int);

	my_put_nbr(nb);
	return (0);
}

int case_c(va_list ap)
{
	char	c = va_arg(ap, int);

	my_putchar(c);
	return (0);
}

int case_u(va_list ap)
{
	unsigned int	nb = va_arg(ap, unsigned int);

	my_put_nbr_base(nb, "0123456789");
	return (0);
}

int case_x(va_list ap)
{
	int	nb = va_arg(ap, int);

	my_put_nbr_base(nb, "0123456789abcdef");
	return (0);
}
