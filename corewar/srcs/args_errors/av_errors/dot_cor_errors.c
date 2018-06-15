/*
** EPITECH PROJECT, 2017
** av_err.c
** File description:
** Arthur
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "virtual.h"

int fct_open(char *av)
{
	if (open(av, O_RDONLY) == -1) {
		my_puterror("Error in function open: No such file "
		"or directory.\n");
		return (84);
	}
	if (open(av, O_DIRECTORY) >= 0) {
		my_puterror("corewar: Error in function read: "
		"Is a directory.\n");
		return (-1);
	}
	return (0);
}

int check_each(char *av)
{
	char	cor[4] = ".cor";
	int	letter = 0;
	int	j = 0;

	if (fct_open(av) == 84)
		return (-1);
	while (av[j] != '.' && av[j] != '\0')
		++j;
	if (av[j] == '\0')
		return (84);
	while (av[j] != '\0') {
		if (av[j] != cor[letter])
			return (84);
		++j;
		++letter;
	}
	if (letter != 4)
		return (84);
	return (0);
}

void error_message(int code, char *av)
{
	if (code == 84) {
		my_puterror(av);
		my_puterror(" is not an executable.\n");
	}
}

int check_cor(char **av, int i)
{
	int	code = 0;

	if ((code = check_each(av[i])) != 0) {
		error_message(code, av[i]);
		return (84);
	}
	return (0);
}
