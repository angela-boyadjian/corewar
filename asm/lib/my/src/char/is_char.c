/*
** EPITECH PROJECT, 2017
** is_char.c
** File description:
** chekc if char is a character
*/

#include "my.h"

int is_char(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}
