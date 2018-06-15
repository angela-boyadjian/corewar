/*
** EPITECH PROJECT, 2018
** fight_loop.c
** File description:
** loop_for_cores_fight
*/

#include "virtual.h"

int fight_loop(circular_memory *vm, champions **champ)
{
	int	cycle_to_die = CYCLE_TO_DIE;
	int	cycle_delta = CYCLE_DELTA;
	int	i = 0;
	int	(*exec_tab[16])(circular_memory *vm, champions *champ);

	init_exec_instru_tab(exec_tab);
	while (cycle_to_die > 0) {
		while (i < cycle_to_die) {
			champ_loop(champ, vm, exec_tab);
			if (vm->nbr_live >= NBR_LIVE) {
				check_live(vm, champ);
			}
			++i;
		}
		cycle_to_die -= cycle_delta;
		i = 0;
	}
	return (0);
}
