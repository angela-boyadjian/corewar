/*
** EPITECH PROJECT, 2017
** argc_err.c
** File description:
** Arthur
*/

#include "virtual.h"

int check_one_ac(int ac, char **av)
{
	int	check = 0;

	if (ac == 1) {
		put_compil_error();
		return (84);
	}
	if (ac == 2) {
		check = fct_open(av[1]);
		if (check == 84)
			return (84);
		else if (check == -1) {
			my_puterror(av[1]);
			my_puterror(" is not an executable\n");
		} else
			put_compil_error();
		return (84);
	}
	return (0);
}
