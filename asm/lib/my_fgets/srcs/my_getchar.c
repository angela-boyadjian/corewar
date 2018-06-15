/*
** EPITECH PROJECT, 2017
** my_getchar.c
** File description:
** <..>
*/

#include "my_fgets.h"

char my_getchar(void)
{
	char	ch = 0;

	read(0, &ch, 1);
	return (ch);
}
