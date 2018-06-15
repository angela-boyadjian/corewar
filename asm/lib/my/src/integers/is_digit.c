/*
** EPITECH PROJECT, 2017
** is_digit.c
** File description:
** check if car is a digit
*/

#include "my.h"

int is_digit(char c)
{
	if (c <= '9' && c >= '0')
		return (1);
	return (0);
}
