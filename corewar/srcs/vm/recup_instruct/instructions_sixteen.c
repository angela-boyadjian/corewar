/*
** EPITECH PROJECT, 2017
** instructions_one_five.c
** File description:
** instr_one_five
*/

#include "virtual.h"

int read_aff(instructions *list, int fd)
{
	if (read(fd, &list->adr, 1) == -1)
		return (-1);
	list->mnemonique = "10";
	if (read(fd, &list->arg1, T_REG) == -1)
		return (-1);
	list->types = 200;
	list->nb_cycles = 2;
	return (0);
}
