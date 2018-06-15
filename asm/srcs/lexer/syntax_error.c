/*
** EPITECH PROJECT, 2017
** syntax_error.c
** File description:
** <..>
*/

#include "corewar.h"

void syntax_error(char *fname, int line)
{
	my_printf("asm, %s, line %d: Syntax error.\n",
			fname, line);
	exit(84);
}