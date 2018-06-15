/*
** EPITECH PROJECT, 2017
** error.c
** File description:
** <..>
*/

#include "my_getopt.h"

static void my_writechar(char ch)
{
	write(1, &ch, 1);
}

static void my_write_str(char *str)
{
	while (*str != '\0')
		my_writechar(*str++);
}

void my_puts(char *name)
{
	my_write_str(name);
	my_write_str(": invalid option -- '");
	my_writechar(my_optopt);
	my_write_str("'\n");
}
