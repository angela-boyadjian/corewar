/*
** EPITECH PROJECT, 2017
** my_printf_color.c
** File description:
** <..>
*/

#include "my_printf.h"

int my_printf_br(va_list arg, char *args)
{
	if (args == 0) {
		my_putstr(KNRM);
		return (0);
	}
	arg++;
	switch (*args) {
		case 'r':
			my_putstr(KRED);
			break;
		case 'g':
			my_putstr(KGRN);
			break;
		case 'l':
			my_putstr(KBLU);
			break;
		default:
			my_putstr(KNRM);
	}
	arg--;
	return (0);
}
