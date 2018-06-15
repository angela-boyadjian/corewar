/*
** EPITECH PROJECT, 2017
** err_gs_acav.c
** File description:
** Arthur
*/

#include "virtual.h"

void put_compil_error(void)
{
	my_puterror("Usage: ./corewar [-g] [-dump cycle_nb] "
	"[[-a load_addr] [-n prog_nb] prog.cor] ...\n");
}

int check_ag(char *argv, char **av, int *i, arguments *dot_cor)
{
	int check = 0;


	if (argv[0] == '-') {
		check = looking_for_flag(av, *i);
		++*i;
	} else {
		check = check_cor(av, *i);
		++dot_cor->cor;
	}
	return (check);
}

void error_champ(int cor)
{
	if (cor == 0)
		my_puterror("No champion specified.\n");
	else
		put_compil_error();
}

int check_double_flag(char **av)
{
	int	hyp_a = 0;
	int	hyp_n = 0;
	int	dump = 0;

	for (int i = 0; av[i]; ++i) {
		if (av[i][0] == '-' && av[i][1] == 'a')
			++hyp_a;
		if (av[i][0] == '-' && av[i][1] == 'n')
			++hyp_n;
		if (av[i][0] == '-' && av[i][1] == 'd')
			++dump;
		if (double_arg(dump, hyp_a, hyp_n) == 84)
			return (84);
		reset_cor(av[i], &hyp_a, &hyp_n);
	}
	return (0);
}

int ar_er(int ac, char **av)
{
	struct arguments	dot_cor;
	int			i = 1;

	dot_cor.cor = 0;
	if (ac == 1) {
		put_compil_error();
		return (84);
	}
	while (i != ac) {
		if (check_ag(av[i], av, &i, &dot_cor) == 84)
			return (84);
		++i;
	}
	if (dot_cor.cor < 2) {
		error_champ(dot_cor.cor);
		return (84);
	}
	return (check_double_flag(av));
}
