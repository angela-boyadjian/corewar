/*
** EPITECH PROJECT, 2017
** init_data_base.c
** File description:
** init_data_base_c
*/

#include "virtual.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int err_init_data_base(instructions **list, arg_champ *av_list, int i)
{
	int	fd = 0;

	if ((fd = open(av_list->cor, O_RDONLY)) == -1) {
		my_puterror("open failed\n");
		return (84);
	}
	if((list[i] = malloc(sizeof(instructions))) == NULL) {
		my_puterror("malloc failed\n");
		return (84);
	}
	if (read_headers(list[i], fd) == -1) {
		my_puterror("bad header\n");
		return (84);
	}
	if ((list[i] = read_instructions(fd, list[i])) == NULL) {
		my_puterror("list failed\n");
		return (84);
	}
	close(fd);
	return (0);
}

int init_data_base(instructions **list, arg_champ *av_list)
{
	int		i = 0;

	while (av_list != NULL) {
		if (err_init_data_base(list, av_list, i) == 84)
			return (84);
		av_list = av_list->next;
		++i;
	}
	list[i] = NULL;
	return (0);
}
