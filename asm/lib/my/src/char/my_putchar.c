/*
** EPITECH PROJECT, 2017
** my_putchar.c
** File description:
** display a character on the screen
*/

#include "my.h"

void my_putchar(char c)
{
	my_print_write_count += write(1, &c, 1);
}
