/*
** EPITECH PROJECT, 2017
** my_putstr.c
** File description:
** afficher_les_char
*/

#include <unistd.h>

int my_strlen(char *str);

void my_putstr(char *str)
{
	write(1, str, my_strlen(str));
}
