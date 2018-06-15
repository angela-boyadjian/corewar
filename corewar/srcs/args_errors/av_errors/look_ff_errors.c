/*
** EPITECH PROJECT, 2017
** look_ff_errors.c
** File description:
** Arthur
*/

#include "virtual.h"

int lf_flag_err(int (*flag_handler[3])(char *flag, char *argv),
char **av, int i)
{
	if (!av[i][1]) {
		my_puterror("Error in function open: "
		"No such file or directory.\n");
		return (84);
	}
	if (g_flag(av[i]) == 84)
		return (84);
	if (!av[i + 1]) {
		my_puterror("Invalid option.\n");
		return (84);
	}
	if (send_to_flag_handler(flag_handler, av, i) == 84)
		return (84);
	return (0);
}

void reset_cor(char *av, int *hyp_a, int *hyp_n)
{
	int j = 0;

	while (av[j] != '\0') {
		if (av[j] == '.') {
			*hyp_a = 0;
			*hyp_n = 0;
			return;
		}
		++j;
	}
}

int double_arg(int dump, int hyp_a, int hyp_n)
{
	if (hyp_a > 1 || hyp_n > 1) {
		my_puterror("Invalid option\n");
		return (84);
	}
	if (dump > 1) {
		my_puterror("Double definition of option dump.\n");
		return (84);
	}
	return (0);
}
