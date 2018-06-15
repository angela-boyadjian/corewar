/*
** EPITECH PROJECT, 2017
** current-file-name
** File description:
** <..>
*/

#include "corewar.h"

void my_memset(void *tab, int place, unsigned int size)
{
	for (unsigned int i = 0; i < size; ++i)
		((char *)tab)[i] = place;
}
