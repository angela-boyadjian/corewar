/*
** EPITECH PROJECT, 2018
** sixteen.c
** File description:
** Arthur
*/

#include "virtual.h"
#include "printf.h"

int aff_instru(circular_memory *vm, champions *champ)
{
	int	rg = getnbr_from_size(champ, T_REG * 2);
	int	nbr = 0;

	(void) vm;
	champ->PC = champ->tmp;
	if (rg > REG_NUMBER)
		return (-1);
	nbr = champ->registers[rg] % 256;
	my_printf("%c", nbr);
	return (0);
}

int modif_carry(int carry)
{
	if (carry == 0)
		return (1);
	else
		return (0);
}
