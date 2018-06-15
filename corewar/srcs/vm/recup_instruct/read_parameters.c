/*
** EPITECH PROJECT, 2017
** read_parameters.c
** File description:
** check_all_params
*/

#include "virtual.h"

int case_one(int *types, int fd, union endian ins)
{
	int	arg = 0;

	*types = *types * 10 + 8;
	if (read(fd, &arg, DIR_SIZE) == -1)
		return (-1);
	ins.val = arg;
	switch_endian_four(&ins);
	return (ins.val);
}

int case_two(int *types, int fd, union endian ins)
{
	int	arg = 0;

	*types = *types * 10 + 4;
	if (read(fd, &arg, IND_SIZE) == -1)
		return (-1);
	ins.val = arg;
	switch_endian_two(&ins);
	return (ins.val);
}

int rd_data_param(int *types, int val, int fd)
{
	int		arg = 0;
	union endian	ins;

	if (val == 1) {
		*types = *types * 10 + 2;
		if (read(fd, &arg, T_REG) == -1)
			return (-1);
		return (arg);
	} else if (val == 2)
		return (case_one(types, fd, ins));
	else
		return (case_two(types, fd, ins));
	return (0);
}

int read_in_struct(instructions *list, int val, int j, int fd)
{
	if (j == 0) {
		list->arg1 = 0;
		if ((list->arg1 = rd_data_param(&list->types, val, fd)) == -1)
			return (-1);
	} else if (j == 1) {
		list->arg2 = 0;
		if ((list->arg2 = rd_data_param(&list->types, val, fd)) == -1)
			return (-1);
	} else {
		list->arg3 = 0;
		if ((list->arg3 = rd_data_param(&list->types, val, fd)) == -1)
			return (-1);
	}
	return (0);
}

int read_parameters(instructions *list, int code, int nb_arg, int fd)
{
	int	bin = 0;
	int	loop = 0;
	int	val = 0;
	int	i = 0;

	if (nb_arg == 2) {
		++nb_arg;
		loop = 1;
	}
	list->types = 0;
	while (nb_arg != loop) {
		val = (code >> nb_arg * 2) ^ bin;
		if (read_in_struct(list, val, i++, fd) == -1)
			return (-1);
		bin |= code >> (nb_arg * 2);
		bin <<= 2;
		--nb_arg;
	}
	return (0);
}
