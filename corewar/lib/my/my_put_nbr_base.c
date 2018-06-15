/*
** EPITECH PROJECT, 2017
** my_put_nbr_base.c
** File description:
** nbrbase
*/

#include <unistd.h>

void my_putchar(char c);
void my_putchar(char c);
int my_strlen(char *);

int my_put_nbr_base(unsigned int nb, char *base)
{
	int	res = nb / my_strlen(base);
	int	rest = nb % my_strlen(base);

	if (res > 0)
		my_put_nbr_base(res, base);
	my_putchar(base[rest]);
	return (0);
}
