/*
** EPITECH PROJECT, 2018
** eleven_to_fifteen.c
** File description:
** Arthur
*/

#include "virtual.h"

int sti_instru(circular_memory *vm, champions *champ)
{
	int	rr = getnbr_from_size(champ, champ->types / 100);
	int	rg = getnbr_from_size(champ, champ->types / 10 % 10);
	int	ld = getnbr_from_size(champ, champ->types % 10);
	int	i = 0;
	char	*str = malloc(sizeof(char) * champ->registers[rr - 1] + 1);

	champ->PC = champ->tmp;
	if (rr > REG_NUMBER)
		return (-1);
	str = its(champ->registers[rr - 1], str);
	memory_put_move(vm, champ, ' ', ((rg + ld) % IDX_MOD));
	memory_put_move(vm, champ, str[i++], 0);
	while (str[i] != '\0')
		memory_put_move(vm, champ, str[i++], 1);
	champ->tmp = champ->PC;
	return (0);
}

int fork_instru(circular_memory *vm, champions *champ)
{
	(void) champ;
	(void) vm;
	(void) champ->types;
	return (0);
}

int lld_instru(circular_memory *vm, champions *champ)
{
	int	ld = 0;
	int	rg = 0;
	int	nbr_to_load = 0;

	(void) vm;
	ld = getnbr_from_size(champ, champ->types / 10);
	rg = getnbr_from_size(champ, champ->types % 10);
	if (rg > REG_NUMBER)
		return (-1);
	champ->PC = champ->tmp;
	memory_put_move(vm, champ, ' ', ld);
	nbr_to_load = getnbr_from_size(champ, REG_SIZE);
	champ->tmp = champ->PC;
	champ->registers[rg - 1] = nbr_to_load;
	return (0);
}

int lldi_instru(circular_memory *vm, champions *champ)
{
	int	ld = getnbr_from_size(champ, champ->types / 100);
	int	nbr = getnbr_from_size(champ, champ->types / 10 % 10);
	int	rg = getnbr_from_size(champ, champ->types % 10);
	int	the_s = 0;
	int	nbr_to_load = 0;

	(void) vm;
	champ->PC = champ->tmp;
	if (rg > REG_NUMBER)
		return (-1);
	memory_put_move(vm, champ, ' ', ld);
	the_s = getnbr_from_size(champ, IND_SIZE) + nbr;
	champ->tmp = champ->PC;
	memory_put_move(vm, champ, ' ', the_s);
	nbr_to_load = getnbr_from_size(champ, REG_SIZE);
	champ->registers[rg - 1] = nbr_to_load;
	champ->tmp = champ->PC;
	champ->carry = modif_carry(champ->carry);
	return (0);
}

int lfork_instru(circular_memory *vm, champions *champ)
{
	(void) champ->types;
	(void) champ;
	(void) vm;
	return (0);
}
