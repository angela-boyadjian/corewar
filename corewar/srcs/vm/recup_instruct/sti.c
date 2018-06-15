/*
** EPITECH PROJECT, 2017
** sti.c
** File description:
** sti_inst
*/

#include "virtual.h"

static void case_one(instructions *list, int fd)
{
	union endian	tmp;

	read(fd, &list->arg2, IND_SIZE);
	tmp.val = list->arg2;
	switch_endian_two(&tmp);
	list->arg2 = tmp.val;
	list->types = list->types * 10 + 4;
}

static void case_two(instructions *list, int fd)
{
	union endian	tmp;

	read(fd, &list->arg3, IND_SIZE);
	tmp.val = list->arg3;
	switch_endian_two(&tmp);
	list->arg3 = tmp.val;
	list->types = list->types * 10 + 4;
}

static void for_i_equal_two(instructions *list, int val, int fd)
{
	if (val != 1)
		case_two(list, fd);
	else {
		read(fd, &list->arg3, T_REG);
		list->types = list->types * 10 + 2;
	}
}

int read_for_sti(instructions *list, int val, int i, int fd)
{
	if (i == 0) {
		if (val != 1)
			return (-1);
		read(fd, &list->arg1, T_REG);
		list->types = 2;
	} else if (i == 1) {
		if (val != 1)
			case_one(list, fd);
		else {
			list->types = list->types * 10 + 2;
			read(fd, &list->arg2, T_REG);
		}
	}
	if (i == 2)
		for_i_equal_two(list, val, fd);
	return (0);
}

int read_sti(instructions *list, int code, int nb_arg, int fd)
{
	int	val = 0;
	int	bin = 0;
	int	i = 0;

	while (nb_arg != 0) {
		val = (code >> nb_arg * 2) ^ bin;
		if (read_for_sti(list, val, i++, fd) == -1)
			return (-1);
		bin |= code >> (nb_arg * 2);
		bin <<= 2;
		--nb_arg;
	}
	return (0);
}
