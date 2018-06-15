/*
** EPITECH PROJECT, 2017
** switch_endian.c
** File description:
** functions_to_switch_endian
*/

#include "virtual.h"

void switch_endian_two(union endian *value)
{
	char	tmp;

	tmp = value->byte[1];
	value->byte[1] = value->byte[0];
	value->byte[0] = tmp;
}

void switch_endian_four(union endian *value)
{
	char	tmp;

	tmp = value->byte[0];
	value->byte[0] = value->byte[3];
	value->byte[3] = tmp;
	tmp = value->byte[1];
	value->byte[1] = value->byte[2];
	value->byte[2] = tmp;
}
