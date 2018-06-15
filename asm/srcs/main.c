/*
** EPITECH PROJECT, 2017
** main.c
** File description:
** main functions
*/

#include "corewar.h"

static void usage(void)
{
	my_printf("USAGE\n"
		"\t./asm file_name[.s]\n\n"
		"DESCRIPTION\n"
		"\tfile_name\tfile in assembly language to be converted into"
		" file_name.core, an\n\t\t\texecutable in the Virtual Machine."
		"\n");
	exit(SUCCESS);
}

static int process_arg(int ch)
{
	if (ch == 'h')
		usage();
	if (ch == '?')
		return (ERROR);
	return (SUCCESS);
}

static char	*get_name(char *av, char *end)
{
	int	index;
	char	*name = malloc(sizeof(*name) * my_strlen(av) + 9);

	if (!name)
		return (NULL);
	for (index = 0; my_strncmp(av + index, ".s", 2) != 0; ++index);
	my_strncpy(name, av, index);
	my_strcat(name, end);
	return (name);
}

static int	write_cor(char *av)
{
	char	*save = malloc(sizeof(*save) * 4096);
	int	file;
	int	c_read = 0;
	int	fd = open(get_name(av, "test"), O_RDONLY);

	file = open(get_name(av, "cor"), O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (fd == ERROR || file == ERROR)
		return (FAILURE);
	while ((c_read = read(fd, save, 4096)) > 0)
		write(file, save, c_read);
	free(save);
	return (SUCCESS);
}

int main(int ac, char **av)
{
	int		fd = 0;
	struct d_queue	*dq = NULL;

	for (int ch = 0; (ch = my_getopt(ac, av, "h")) != -1;)
		if (process_arg(ch) < 0)
			return (FAILURE);
	if (my_optind == SUCCESS)
		return (FAILURE);
	for (int i = my_optind; i < ac; i++) {
		dq = lex_file(av[i]);
		if (!dq)
			continue;
		fd = open(get_name(av[i], "test"),
		O_WRONLY | O_TRUNC | O_CREAT, 0644);
		if (fd == ERROR)
			return (FAILURE);
		parser(dq, fd);
	}
	close(fd);
	return (write_cor(av[1]));
}
