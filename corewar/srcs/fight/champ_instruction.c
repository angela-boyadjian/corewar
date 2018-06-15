/*
** EPITECH PROJECT, 2017
** champ_instruction.c
** File description:
** champ_instructions_c_
*/

#include "virtual.h"

int is_adr(int ins)
{
	if (ins == 2 || ins == 3)
		return (1);
	else if (ins >= 6 && ins <= 8)
		return (1);
	if (ins == 10 || ins == 11)
		return (1);
	else if (ins == 13 || ins == 14)
		return (1);
	return (0);
}

int nb_params_ins(int ins)
{
	if (ins == 2 || ins == 3 || ins == 13)
		return (2);
	else if (ins >= 6 && ins <= 8)
		return (3);
	if (ins == 10 || ins == 11 || ins == 14)
		return (3);
	return (0);
}

int champ_instru(champions *champ)
{
	if (champ->cycle != 0)
		return (0);
	while (champ->inst == 0)
		champ->inst = rec_instru(champ);
	champ->PC = champ->tmp;
	if (is_adr(champ->inst) == 1) {
		champ->types = champ_params_types(champ,
				nb_params_ins(champ->inst));
	}
	champ->cycle = inst_cycle(champ->inst);
	return (0);
}

int exec_instruc(champions *champ, circular_memory *vm,
int (*exec_tab[16])(circular_memory *vm, champions *champ))
{
	if (champ->cycle != 0)
		return (0);
	exec_tab[0](vm, champ);
	return (0);
}

int champ_loop(champions **champ, circular_memory *vm,
int (*exec_tab[16])(circular_memory *vm, champions *champ))
{
	int	i = 0;

	while (champ[i] != NULL) {
		if (champ[i]->alive == 1) {
			champ_instru(champ[i]);
			--champ[i]->cycle;
			exec_instruc(champ[i++], vm, exec_tab);
		}
	}
	return (0);
}
