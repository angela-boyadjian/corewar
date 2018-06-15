/*
** EPITECH PROJECT, 2017
** error.c
** File description:
** <..>
*/

#include "corewar.h"

void *file_error(char *fname)
{
	my_printf("%s: does not exist\n", fname);
	return (NULL);
}

void malloc_error(void)
{
	write(2, "Error: malloc NULL pointer\n", 27);
	exit(84);
}

void error_invalid_instruct(char *fname, int line)
{
	my_printf("asm, %s, line %d: Invalid instruction.\n", fname, line);
	exit(84);
}

void error_name(char *fname, int line)
{
	my_printf("asm, %s, line %d: The name can only be defined once.\n",
			fname, line);
	exit(84);
}

void error_comment(char *fname, int line)
{
	my_printf("asm, %s, line %d: The comment can only be defined once.\n",
			fname, line);
	exit(84);
}
