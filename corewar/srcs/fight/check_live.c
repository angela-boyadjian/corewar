/*
** EPITECH PROJECT, 2018
** check_live.c
** File description:
** Arthur
*/

#include "virtual.h"
#include "printf.h"

int id_win(champions **champ, int last_live)
{
	int	i = 0;

	while (champ[i] != NULL) {
		if (champ[i]->registers[0] == last_live)
			return (champ[i]->registers[0]);
		++i;
	}
	return (0);
}

int check_live(circular_memory *vm, champions **champ)
{
	int	i = 0;
	int	nbr_still_alive = 0;
	int	nb = 0;

	while (champ[i] != NULL) {
		if (champ[i++]->nb_live > 0)
			++nbr_still_alive;
	}
	if (nbr_still_alive > 1) {
		vm->nbr_live = 0;
		return (0);
	} else {
		nb = id_win(champ, vm->last_live);
		my_printf("Le joueur %d (%s) a gagné.\n", nb,
				champ[nb - 1]->name);
		print_memory(vm->memory);
		exit (0);
	}
	return (0);
}

int inst_cycle(int ins)
{
	return (op_tab[ins - 1].nbr_cycles);
}
