/*
** EPITECH PROJECT, 2018
** one_to_five.c
** File description:
** Arthur
*/

#include "virtual.h"
#include "printf.h"

int live_instru(circular_memory *vm, champions *champ)
{
	(void) champ;
	(void) vm;
	getnbr_from_size(champ, 8);
	++champ->tmp;
	champ->PC = champ->tmp;
	my_printf("Le joueur %d (%s) est en vie.\n", champ->registers[0],
	champ->name);
	vm->last_live = champ->registers[0];
	++vm->nbr_live;
	vm->last_live = champ->registers[0];
	return (0);
}

int ld_instru(circular_memory *vm, champions *champ)
{
	int	ld = 0;
	int	rg = 0;
	int	nbr_to_load = 0;

	(void) vm;
	ld = getnbr_from_size(champ, champ->types / 10);
	rg = getnbr_from_size(champ, champ->types % 10);
	champ->PC = champ->tmp;
	memory_put_move(vm, champ, ' ', (ld % IDX_MOD));
	nbr_to_load = getnbr_from_size(champ, REG_SIZE);
	champ->tmp = champ->PC;
	if (rg > REG_NUMBER)
		return (-1);
	champ->registers[rg - 1] = nbr_to_load;
	champ->tmp = champ->PC;
	return (0);
}

int st_instru(circular_memory *vm, champions *champ)
{
	int	rg = getnbr_from_size(champ, champ->types / 10);
	int	ld = getnbr_from_size(champ, champ->types % 10);
	int	i = 0;
	char	*str = malloc(sizeof(char) * champ->registers[rg - 1] + 1);

	champ->PC = champ->tmp;
	str = its(champ->registers[rg - 1], str);
	if (champ->types % 10 == 8) {
		memory_put_move(vm, champ, ' ', (ld % IDX_MOD));
		memory_put_move(vm, champ, str[i++], 0);
		while (str[i] != '\0')
			memory_put_move(vm, champ, str[i++], 1);
	} else {
		champ->registers[rg - 1] = champ->registers[ld - 1];
	}
	champ->tmp = champ->PC;
	free(str);
	return (0);
}

int add_instru(circular_memory *vm, champions *champ)
{
	int	r1 = getnbr_from_size(champ, T_REG * 2);
	int	r2 = getnbr_from_size(champ, T_REG * 2);
	int	r3 = getnbr_from_size(champ, T_REG * 2);

	(void) vm;
	champ->PC = champ->tmp;
	if (r1 > REG_NUMBER || r2 > REG_NUMBER || r3 > REG_NUMBER)
		return (-1);
	champ->registers[r3 - 1] = champ->registers[r1 - 1]
	+ champ->registers[r2 - 1];
	champ->carry = modif_carry(champ->carry);
	return (0);
}

int sub_instru(circular_memory *vm, champions *champ)
{
	int	r1 = getnbr_from_size(champ, T_REG * 2);
	int	r2 = getnbr_from_size(champ, T_REG * 2);
	int	r3 = getnbr_from_size(champ, T_REG * 2);

	(void) vm;
	champ->PC = champ->tmp;
	if (r1 > REG_NUMBER || r2 > REG_NUMBER || r3 > REG_NUMBER)
		return (-1);
	champ->registers[r3 - 1] = champ->registers[r1 - 1]
	- champ->registers[r2 - 1];
	champ->carry = modif_carry(champ->carry);
	return (0);
}
