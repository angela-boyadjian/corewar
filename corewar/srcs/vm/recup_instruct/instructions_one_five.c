/*
** EPITECH PROJECT, 2017
** instructions_one_five.c
** File description:
** instr_one_five
*/

#include "virtual.h"

int read_live(instructions *list, int fd)
{
	union endian	tmp;

	list->mnemonique = "01";
	read(fd, &list->arg1, 4);
	tmp.val = list->arg1;
	switch_endian_four(&tmp);
	list->arg1 = tmp.val;
	list->nb_cycles = 10;
	list->types = 800;
	return (0);
}

int read_ld(instructions *list, int fd)
{
	read(fd, &list->adr, 1);
	list->mnemonique = "02";
	if (read_parameters(list, list->adr, 2, fd) != 0)
		return (-1);
	list->types *= 10;
	list->types += 0;
	list->nb_cycles = 5;
	return (0);
}

int read_st(instructions *list, int fd)
{
	read(fd, &list->adr, 1);
	list->mnemonique = "03";
	if (read_parameters(list, list->adr, 2, fd) != 0)
		return (-1);
	list->types = list->types * 10;
	list->nb_cycles = 5;
	return (0);
}

int read_add(instructions *list, int fd)
{
	read(fd, &list->adr, 1);
	list->mnemonique = "04";
	if (read_parameters(list, list->adr, 3, fd) != 0)
		return (-1);
	list->nb_cycles = 10;
	return (0);
}

int read_sub(instructions *list, int fd)
{
	read(fd, &list->adr, 1);
	list->mnemonique = "05";
	if (read_parameters(list, list->adr, 3, fd) != 0)
		return (-1);
	list->nb_cycles = 10;
	return (0);
}
