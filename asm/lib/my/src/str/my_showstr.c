/*
** EPITECH PROJECT, 2017
** my_showstr.c
** File description:
** show a string
*/

#include "my.h"

int my_showstr(char const *str)
{
	while (*str != '\0') {
		if (*str >= ' ' && *str <= '~') {
			my_putchar(*str++);
		} else {
			my_putchar('\\');
			my_putnbr_base(*str++, "0123456789abcdef");
		}
	}
	return (0);
}
