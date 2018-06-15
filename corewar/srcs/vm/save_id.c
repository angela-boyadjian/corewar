/*
** EPITECH PROJECT, 2017
** save_id.c
** File description:
** save_id_c_
*/

#include "virtual.h"

int save_id(char **champ_name, champions **champ)
{
	int	i = 0;

	while (champ[i] != NULL) {
		champ_name[champ[i]->registers[0] - 1] =
		malloc(sizeof(char*) * (my_strlen(champ[i]->name) + 1));
		if (champ_name[champ[i]->registers[0] - 1] == NULL)
			return (-1);
		my_strcpy(champ_name[champ[i]->registers[0] - 1],
				champ[i]->name);
		++i;
	}
	champ_name[4] = NULL;
	return (0);
}
