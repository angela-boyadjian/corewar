/*
** EPITECH PROJECT, 2017
** clist_argv.c
** File description:
** Arthur
*/

#include "virtual.h"

int find_a(char **av, int i)
{
	if (i - 2 > 0 && av[i - 2][1] == 'a')
		return (my_getnbr(av[i - 1]));
	if (i - 4 > 0 && av[i - 4][1] == 'a')
		return (my_getnbr(av[i - 3]));
	return (0);
}

int find_n(char **av, int i)
{
	static int	nbr = 0;

	if (i - 2 > 0 && av[i - 2][1] == 'n')
		return (my_getnbr(av[i - 1]));
	if (i - 4 > 0 && av[i - 4][1] == 'n')
		return (my_getnbr(av[i - 3]));
	++nbr;
	return (nbr);
}

arg_champ *put_in_list(arg_champ *clt, char **av, int i)
{
	static int	status = 0;

	if (status == 0) {
		clt = init_ag_champ(find_a(av, i), find_n(av, i), av[i]);
		if (clt == NULL)
			exit (84);
		status = 1;
	} else
		if (insert_end(&clt, find_a(av, i), find_n(av, i), av[i]) == 84)
			exit (84);
	return (clt);
}

int verif_cor(char *av)
{
	int	i = 0;

	while (av[i] != '\0') {
		if (av[i] == '.')
			return (1);
		++i;
	}
	return (0);
}

arg_champ *put_arg(int ac, char **av)
{
	int		i = 1;
	arg_champ	*clist = NULL;

	while (i != ac) {
		if (verif_cor(av[i]) == 1) {
			clist = put_in_list(clist, av, i);
			++clist->nbr_champ;
		}
		++i;
	}
	insert_nbr_champ(&clist, clist->nbr_champ);
	return (clist);
}
