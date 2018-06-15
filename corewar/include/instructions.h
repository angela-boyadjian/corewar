/*
** EPITECH PROJECT, 2018
** instructions.h
** File description:
** Arthur
*/

#ifndef INSTR_H_
#define INSTR_H_

int live_instru(circular_memory *vm, champions *champ);
int ld_instru(circular_memory *vm, champions *champ);
int st_instru(circular_memory *vm, champions *champ);
int add_instru(circular_memory *vm, champions *champ);
int sub_instru(circular_memory *vm, champions *champ);
int and_instru(circular_memory *vm, champions *champ);
int or_instru(circular_memory *vm, champions *champ);
int xor_instru(circular_memory *vm, champions *champ);
int zjmp_instru(circular_memory *vm, champions *champ);
int ldi_instru(circular_memory *vm, champions *champ);
int sti_instru(circular_memory *vm, champions *champ);
int fork_instru(circular_memory *vm, champions *champ);
int lld_instru(circular_memory *vm, champions *champ);
int lldi_instru(circular_memory *vm, champions *champ);
int lfork_instru(circular_memory *vm, champions *champ);
int aff_instru(circular_memory *vm, champions *champ);
int modif_carry(int carry);

#endif
