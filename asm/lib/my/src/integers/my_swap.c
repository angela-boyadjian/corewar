/*
** EPITECH PROJECT, 2017
** my_swap
** File description:
** swap 2 vars.
*/

#include "my.h"

void my_swap(int *a, int *b)
{
	int	tmp;

	if (a != 0 && b != 0) {
		tmp = *a;
		*a = *b;
		*b = tmp;
	}
}
