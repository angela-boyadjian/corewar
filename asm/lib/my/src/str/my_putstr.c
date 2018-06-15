/*
** EPITECH PROJECT, 2017
** my_putstr
** File description:
** write a string on stdout
*/

#include "my.h"

int my_putstr(char const *str)
{
	int	i;

	i = 0;
	if (str == 0)
		return (-1);
	while (*(str + i) != '\0')
		my_putchar(*(str + i++));
	return (0);
}
