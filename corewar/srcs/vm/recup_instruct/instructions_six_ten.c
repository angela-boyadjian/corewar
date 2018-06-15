/*
** EPITECH PROJECT, 2017
** instructions_six_ten.c
** File description:
** instr_six_ten
*/

#include "virtual.h"

int read_and(instructions *list, int fd)
{
	read(fd, &list->adr, 1);
	list->mnemonique = "06";
	if (read_parameters(list, list->adr, 3, fd) != 0)
		return (-1);
	list->nb_cycles = 6;
	return (0);
}

int read_or(instructions *list, int fd)
{
	read(fd, &list->adr, 1);
	list->mnemonique = "07";
	if (read_parameters(list, list->adr, 3, fd) != 0)
		return (-1);
	list->nb_cycles = 6;
	return (0);
}

int read_xor(instructions *list, int fd)
{
	read(fd, &list->adr, 1);
	list->mnemonique = "08";
	if (read_parameters(list, list->adr, 3, fd) != 0)
		return (-1);
	list->nb_cycles = 6;
	return (0);
}

int read_zjmp(instructions *list, int fd)
{
	union endian	tmp;

	list->mnemonique = "09";
	read(fd, &list->arg1, 2);
	tmp.val = list->arg1;
	switch_endian_two(&tmp);
	list->arg1 = tmp.val;
	list->nb_cycles = 25;
	list->types = 400;
	return (0);
}

int read_ldi_instruction(instructions *list, int fd)
{
	read(fd, &list->adr, 1);
	list->mnemonique = "0A";
	if (read_ldi(list, list->adr, 3, fd) != 0)
		return (-1);
	list->nb_cycles = 25;
	return (0);
}
