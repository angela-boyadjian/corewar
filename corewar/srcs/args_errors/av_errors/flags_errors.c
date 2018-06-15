/*
** EPITECH PROJECT, 2017
** flags_err.c
** File description:
** Arthur
*/

#include "virtual.h"

int check_dump(char *av)
{
	char	dmp[5] = "-dump";
	int	i = 0;

	while (av[i] != '\0' && dmp[i] != '\0') {
		if (av[i] != dmp[i])
			return (84);
		++i;
	}
	if (av[i] != dmp[i])
		return (84);
	return (0);
}

int check_fl_n(char *flag, char *av)
{
	char	base[10] = "0123456789";
	int	j = 0;

	(void) flag;
	for (int i = 0; av[i] != '\0'; ++i) {
		while (base[j] != av[i] && base[j] != '\0')
			++j;
		if (base[j] == '\0') {
			my_puterror("Invalid option.\n");
			return (84);
		}
		j = 0;
	}
	if (my_getnbr(av) < 1 || my_getnbr(av) > 4) {
		my_puterror("-n argument ");
		my_puterror(av);
		my_puterror(" is invalid.\nEnter a number between 1 and 4.\n");
		return (84);
	}
	return (0);
}

int check_fl_a(char *flag, char *params)
{
	char	base[10] = "0123456789";
	int	i = 0;
	int	j = 0;

	(void) flag;
	while (params[i] != '\0') {
		while (params[i] != base[j] && base[j] != '\0')
			++j;
		if (base[j] == '\0') {
			my_puterror("-a argument ");
			my_puterror(params);
			my_puterror(" is invalid\n"
			"Enter a valid memory offset.\n");
			return (84);
		}
		j = 0;
		++i;
	}
	return (0);
}

int g_flag(char *av)
{
	if (av[0] == '-' && av[1] == 'g') {
		my_puterror("We don't have any graphic interface\n");
		return (84);
	}
	return (0);
}

int hexa_gest(char *av, char *params)
{
	char	hexa[16] = "0123456789ABCDEF";
	int	i = 1;
	int	j = 0;

	if (check_dump(av) == 84)
		return (84);
	while (params[i] != '\0') {
		while (params[i] != hexa[j] && hexa[j] != '\0')
			++j;
		if (hexa[j] == '\0')
			return (84);
		j = 0;
		++i;
	}
	if (i == 1)
		return (84);
	return (0);
}
