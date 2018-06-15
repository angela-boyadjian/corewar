/*
** EPITECH PROJECT, 2017
** check_for_flags.c
** File description:
** Arthur
*/

#include "virtual.h"

int double_fg(char flag)
{
	static int	flag_dump = OFF;

	if (flag == 'd' && flag_dump == OFF) {
		flag_dump = ON;
		return (D);
	} else if (flag == 'd' && flag_dump == ON) {
		my_puterror("Double definition of option dump.\n");
		return (84);
	}
	if (flag == 'n')
		return (N);
	if (flag == 'a')
		return (A);
	my_puterror("Error in function open: No such file or directory.\n");
	return (84);
}

static void init_flag_handler(int (*flag_handler[3])(char *flag, char *argv))
{
	flag_handler[0] = &hexa_gest;
	flag_handler[1] = &check_fl_a;
	flag_handler[2] = &check_fl_n;
}

int send_to_flag_handler(int (*flag_handler[3])(char *flag, char *argv),
char **av, int i)
{
	int fg = 0;

	if ((fg = double_fg(av[i][1])) == 84)
		return (84);
	if (flag_handler[fg](av[i], av[i + 1]) == 84)
		return (84);
	return (0);
}

int looking_for_flag(char **av, int i)
{
	int	(*flag_handler[3])(char *flag, char *argv);

	init_flag_handler(flag_handler);
	if (lf_flag_err(flag_handler, av, i) == 84)
		return (84);
	return (0);
}
