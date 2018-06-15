/*
** EPITECH PROJECT, 2017
** my_puterror.c
** File description:
** blabla
*/

#include <unistd.h>

int my_strlen(char const *str);

void my_puterror(char *str)
{
	write(2, str, my_strlen(str));
}
