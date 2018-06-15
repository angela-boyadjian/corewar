/*
** EPITECH PROJECT, 2017
** exec_instructions.c
** File description:
** exec_instructions_c_
*/

#include "virtual.h"

void init_exec_instru_tab(int (*exec_instru_tab[16])(circular_memory *vm,
champions *champ))
{
	exec_instru_tab[0] = &live_instru;
	exec_instru_tab[1] = &ld_instru;
	exec_instru_tab[2] = &st_instru;
	exec_instru_tab[3] = &add_instru;
	exec_instru_tab[4] = &sub_instru;
	exec_instru_tab[5] = &and_instru;
	exec_instru_tab[6] = &or_instru;
	exec_instru_tab[7] = &xor_instru;
	exec_instru_tab[8] = &zjmp_instru;
	exec_instru_tab[9] = &ldi_instru;
	exec_instru_tab[10] = &sti_instru;
	exec_instru_tab[11] = &fork_instru;
	exec_instru_tab[12] = &lld_instru;
	exec_instru_tab[13] = &lldi_instru;
	exec_instru_tab[14] = &lfork_instru;
	exec_instru_tab[15] = &aff_instru;
}
