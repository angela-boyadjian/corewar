/*
** EPITECH PROJECT, 2017
** pars_champ.c
** File description:
** pars_champ.c
*/

#include "virtual.h"

int rec_instru(champions *champ)
{
	int	inst = 0;
	char	*tmp = malloc(sizeof(char) * 3);

	tmp[0] = *champ->tmp;
	champ->tmp += 1;
	tmp[1] = *champ->tmp;
	tmp[2] = '\0';
	champ->tmp += 1;
	inst = my_getnbr_base(tmp, "0123456789ABCDEF");
	free(tmp);
	if (inst < 1 || inst > 16)
		return (0);
	else
		return (inst);
}

int rec_adr(champions *champ)
{
	int	adr = 0;
	char	*tmp = malloc(sizeof(char) * 3);

	tmp[0] = *champ->tmp;
	champ->tmp += 1;
	tmp[1] = *champ->tmp;
	tmp[2] = '\0';
	champ->tmp += 1;
	adr = my_getnbr_base(tmp, "0123456789ABCDEF");
	free(tmp);
	return (adr);
}

int champ_params_types(champions *champ, int nb_params)
{
	int	types = 0;
	int	bin = 0;
	int	val = 0;
	int	loop = 0;
	int	adr = 0;

	adr = rec_adr(champ);
	if (nb_params == 2) {
		++nb_params;
		loop = 1;
	}
	while (nb_params != loop) {
		val = (adr >> nb_params * 2) ^ bin;
		types = types + val * 2 * 10;
		bin |= adr >> (nb_params * 2);
		bin <<= 2;
		--nb_params;
	}
	return (types);
}
