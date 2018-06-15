/*
** EPITECH PROJECT, 2017
** cases2.c
** File description:
** Case
*/

#include "../../../include/my.h"
#include <unistd.h>

int case_o(va_list ap)
{
	int	nb = va_arg(ap, int);

	my_put_nbr_base(nb, "01234567");
	return (0);
}

int case_p(va_list ap)
{
	long	nb = va_arg(ap, long);

	if (nb == 0) {
		write(1, "(nil)", 5);
		return (0);
	}
	my_putstr("0x");
	my_put_nbr_base_long(nb, "0123456789abcdef");
	return (0);
}

int case_b(va_list ap)
{
	unsigned int	nb = va_arg(ap, unsigned int);

	my_put_nbr_base(nb, "01");
	return (0);
}

int case_mod(va_list ap)
{
	my_putchar('%');
	return (0);
}

int case_smaj(va_list ap)
{
	char	*str = va_arg(ap, char *);
	int	i = 0;

	while (str[i] != '\0') {
		if (str[i] > 32 && str[i] <= 127)
			my_putchar(str[i]);
		else {
			my_putchar('\\');
			if (str[i] <= 7)
				my_putchar('0');
			if (str[i] == 127)
				my_putchar('0');
			my_put_nbr_base(str[i], "01234567");
		}
		i++;
	}
	return (0);
}