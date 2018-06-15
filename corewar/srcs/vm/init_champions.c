/*
** EPITECH PROJECT, 2017
** init_champions.c
** File description:
** init_champions_c
*/

#include "virtual.h"

int memset_champion_registers(champions *champ)
{
	int		i = 0;
	static int	nb = 1;

	champ->inst = 0;
	champ->alive = 1;
	champ->cycle = 0;
	champ->carry = 0;
	champ->nb_live = 0;
	champ->types = 0;
	champ->registers = malloc(sizeof(int) * (REG_NUMBER + 1));
	if (champ->registers == NULL)
		return (84);
	champ->registers[i++] = nb++;
	while (i != REG_NUMBER)
		champ->registers[i++] = 0;
	champ->registers[i] = 0;
	champ->carry = 0;
	return (0);
}

int init_champions(champions **champ, arg_champ *av_list)
{
	int		i = -1;
	instructions	**data_base = malloc(sizeof(instructions) *
			(av_list->nbr_champ + 1));

	if (data_base == NULL)
		return (84);
	if (init_data_base(data_base, av_list) == 84)
		return (84);
	while (data_base[++i] != NULL) {
		if ((champ[i] = malloc(sizeof(champions))) == NULL)
			return (84);
		if (memset_champion_registers(champ[i]) == 84)
			return (84);
		champ[i]->list = data_base[i];
		champ[i]->name = malloc(sizeof(char) *
				(my_strlen(champ[i]->list->name) + 1));
		my_strcpy(champ[i]->name, champ[i]->list->name);
	}
	champ[i] = NULL;
	return (0);
}
