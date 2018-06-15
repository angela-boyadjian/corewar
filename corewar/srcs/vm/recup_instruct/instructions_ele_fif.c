/*
** EPITECH PROJECT, 2017
** instructions_ele_fif.c
** File description:
** instr_ele_fif
*/

#include "virtual.h"

int read_sti_instruction(instructions *list, int fd)
{
	read(fd, &list->adr, 1);
	list->mnemonique = "0B";
	if (read_sti(list, list->adr, 3, fd) == -1)
		return (-1);
	list->nb_cycles = 25;
	return (0);
}

int read_fork(instructions *list, int fd)
{
	union endian	tmp;

	list->mnemonique = "0C";
	read(fd, &list->arg1, IND_SIZE);
	tmp.val = list->arg1;
	switch_endian_two(&tmp);
	list->arg1 = tmp.val;
	list->nb_cycles = 800;
	list->types = 400;
	return (0);
}

int read_lld(instructions *list, int fd)
{
	read(fd, &list->adr, 1);
	list->mnemonique = "0D";
	if (read_parameters(list, list->adr, 2, fd) != 0)
		return (-1);
	list->nb_cycles = 10;
	return (0);
}

int read_lldi(instructions *list, int fd)
{
	read(fd, &list->adr, 1);
	list->mnemonique = "0E";
	if (read_ldi(list, list->adr, 3, fd) != 0)
		return (-1);
	list->nb_cycles = 50;
	return (0);
}

int read_lfork(instructions *list, int fd)
{
	read(fd, &list->adr, 1);
	list->mnemonique = "0F";
	if (read_parameters(list, list->adr, 1, fd) != 0)
		return (-1);
	list->nb_cycles = 1000;
	return (0);
}
