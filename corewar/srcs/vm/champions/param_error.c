/*
** EPITECH PROJECT, 2017
** param_error.c
** File description:
** param_error.c
*/

#include "virtual.h"
#include "op.h"

static int recup_type(int types)
{
	if (types == 2)
		return (T_REG);
	if (types == 8)
		return (T_DIR);
	if (types == 4)
		return (T_IND);
	return (0);
}

static int or_types(int types)
{
	int	nb1 = 0;
	int	nb2 = 0;
	int	nb3 = 0;

	nb1 = recup_type(types / 100);
	nb2 = recup_type(types / 10 % 10);
	nb3 = recup_type(types % 10);
	return (nb1 | nb2 | nb3);
}

static int know_params_nb(int types)
{
	if (types % 10 != 0 && types / 10 % 10 != 0)
		return (3);
	if (types % 10 != 0)
		return (2);
	if (types / 100 != 0)
		return (2);
	return (1);
}

int is_good_params(int types, int inst)
{
	int	nb_params = 0;

	nb_params = know_params_nb(types);
	if (or_types(types) != op_tab[inst - 1].type[nb_params])
		return (-1);
	return (0);
}
