/*
** EPITECH PROJECT, 2017
** my_getopt.c
** File description:
** the getopt function
*/

#include "my_getopt.h"

char *dup_str(char const *src)
{
	char	*str;
	int	i = 0;
	int	len = 0;

	if (src == 0)
		return (0);
	while (src[len] != '\0')
		len++;
	str = (char *)malloc(sizeof(char) * (len + 1));
	while (src[i] != '\0') {
		str[i] = src[i];
		++i;
	}
	str[i] = '\0';
	return (str);
}

static void sort_av(int ac, char *av[], const char *optstring)
{
	int	i = 1;

	while (i < ac) {
		if (av[i][0] == '-' && in_optstring(optstring, av[i][1]) &&
				has_arg(optstring, av[i][1])) {
			i += 2;
		} else if (av[i][0] != '-') {
			move_arr(av, i);
			ac--;
		} else {
			++i;
		}
	}
}

static void init_get_opt(int ac, char *av[], const char *optstring)
{
	int	x = 0;
	struct optarg	*tmp = 0;

	if (crnt == 0) {
		sort_av(ac, av, optstring);
		tmp = (struct optarg *)malloc(sizeof(struct optarg));
		crnt = tmp;
		for (x = 1; x < ac; x++) {
			tmp->opt = get_flag(av[x], &x, optstring);
			tmp->no = x;
			tmp->next = (struct optarg *)malloc(
						sizeof(struct optarg));
			tmp = tmp->next;
		}
	}
}

static int get_argument(const char *optstring, char *tmp)
{
	if (crnt != 0 && has_arg(optstring, *tmp)) {
		if (len(crnt->opt) != 2) {
			my_optarg = dup_str(crnt->opt + 2);
			return (0);
		}
		if (crnt->next != 0 && crnt->next->opt != 0) {
			crnt = crnt->next;
			my_optarg = crnt->opt;
		} else {
			*tmp = '?';
		}
	}
	return (0);
}

int my_getopt(int argc, char *argv[], const char *optstring)
{
	char	tmp = 0;

	if (argc == 1)
		return (-1);
	init_get_opt(argc, argv, optstring);
	my_optind = crnt->no;
	if (crnt->opt != 0 && crnt->opt[0] == '-') {
		if (!in_optstring(optstring, crnt->opt[1])) {
			my_optopt = crnt->opt[1];
			crnt = crnt->next;
			my_puts(argv[0]);
			return ('?');
		} else {
			tmp = crnt->opt[1];
			my_optopt = tmp;
			get_argument(optstring, &tmp);
			crnt = crnt->next;
			return (tmp);
		}
	}
	return (-1);
}
