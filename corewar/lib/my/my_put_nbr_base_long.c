/*
** EPITECH PROJECT, 2017
** my_put_nbr_base_long.c
** File description:
** baselong
*/

#include <unistd.h>

void my_putchar(char c);
void my_putchar(char c);
int my_strlen(char *);

long my_put_nbr_base_long(long long nb, char *base)
{
	long	res = nb / my_strlen(base);
	long	rest = nb % my_strlen(base);

	if (res > 0)
		my_put_nbr_base_long(res, base);
	my_putchar(base[rest]);
	return (0);
}
