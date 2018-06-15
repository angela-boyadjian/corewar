/*
** EPITECH PROJECT, 2018
** instruction.c
** File description:
** functions for the instructions
*/
#include "corewar.h"

int	get_cmd(char *cmd)
{
	if (cmd == NULL)
		return (FAILURE);
	for (int i = 0; op_tab[i].mnemonique != NULL; ++i) {
		if (my_strcmp(cmd, op_tab[i].mnemonique) == 0)
			return (i);
	}
	return (FAILURE);
}

void	add_cmd(struct token *token, int fd)
{
	int	index = get_cmd(token->mnemo);

	if (index != FAILURE && token->tk_val == I)
		write(fd, &(op_tab[index].code), 1);
}