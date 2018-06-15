/*
** EPITECH PROJECT, 2018
** six_to_ten.c
** File description:
** Arthur
*/

#include "virtual.h"

int and_instru(circular_memory *vm, champions *champ)
{
	int	r1 = getnbr_from_size(champ, champ->types / 100);
	int	r2 = getnbr_from_size(champ, champ->types / 10 % 10);
	int	r3 = getnbr_from_size(champ, champ->types % 10);

	(void) vm;
	champ->PC = champ->tmp;
	if (r1 > REG_NUMBER || r2 > REG_NUMBER || r3 > REG_NUMBER)
		return (-1);
	champ->registers[r3 - 1] = champ->registers[r1 - 1]
	& champ->registers[r2 - 1];
	champ->carry = modif_carry(champ->carry);
	return (0);
}

int or_instru(circular_memory *vm, champions *champ)
{
	int	r1 = getnbr_from_size(champ, champ->types / 100);
	int	r2 = getnbr_from_size(champ, champ->types / 10 % 10);
	int	r3 = getnbr_from_size(champ, champ->types % 10);

	(void) vm;
	champ->PC = champ->tmp;
	if (r1 > REG_NUMBER || r2 > REG_NUMBER || r3 > REG_NUMBER)
		return (-1);
	champ->registers[r3 - 1] = champ->registers[r1 - 1]
	| champ->registers[r2 - 1];
	champ->carry = modif_carry(champ->carry);
	return (0);
}

int xor_instru(circular_memory *vm, champions *champ)
{
	int	r1 = getnbr_from_size(champ, champ->types / 100);
	int	r2 = getnbr_from_size(champ, champ->types / 10 % 10);
	int	r3 = getnbr_from_size(champ, champ->types % 10);

	(void) vm;
	champ->PC = champ->tmp;
	if (r1 > REG_NUMBER || r2 > REG_NUMBER || r3 > REG_NUMBER)
		return (-1);
	champ->registers[r3 - 1] = champ->registers[r1 - 1]
	^ champ->registers[r2 - 1];
	champ->carry = modif_carry(champ->carry);
	return (0);
}

int zjmp_instru(circular_memory *vm, champions *champ)
{
	int	jump = 0;

	(void) vm;
	if (champ->carry == 1) {
		jump = getnbr_from_size(champ, champ->types) % IDX_MOD;
		memory_put_move(vm, champ, ' ', jump);
		champ->tmp = champ->PC;
	}
	return (0);
}

int ldi_instru(circular_memory *vm, champions *champ)
{
	int	ld = 0;
	int	nbr = 0;
	int	rg = 0;
	int	the_s = 0;
	int	nbr_to_load = 0;

	(void) vm;
	ld = getnbr_from_size(champ, champ->types / 100);
	nbr = getnbr_from_size(champ, champ->types / 10 % 10);
	rg = getnbr_from_size(champ, champ->types % 10);
	champ->PC = champ->tmp;
	if (rg > REG_NUMBER)
		return (-1);
	memory_put_move(vm, champ, ' ', (ld % IDX_MOD));
	the_s = getnbr_from_size(champ, IND_SIZE) + nbr;
	memory_put_move(vm, champ, ' ', (the_s % IDX_MOD));
	nbr_to_load = getnbr_from_size(champ, REG_SIZE);
	champ->registers[rg - 1] = nbr_to_load;
	champ->tmp = champ->PC;
	return (0);
}
