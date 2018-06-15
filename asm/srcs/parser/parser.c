/*
** EPITECH PROJECT, 2018
** parser.c
** File description:
** parseur for asm
*/
#include "corewar.h"

void	swap_endian(union endian *result)
{
	char	tmp;

	tmp = result->byte[3];
	result->byte[3] = result->byte[0];
	result->byte[0] = tmp;
	tmp = result->byte[2];
	result->byte[2] = result->byte[1];
	result->byte[1] = tmp;
}

void	parser(struct d_queue *head, int fd)
{
	struct	d_queue	*tmp = head->next;
	struct	token	*token;

	add_header(head, fd);
	while (tmp != NULL) {
		token = tmp->token;
		if (token->tk_val == L) {
			if (tmp->next == NULL)
				break;
			tmp = tmp->next;
			token = tmp->token;
		}
		error_handling(token);
		add_cmd(token, fd);
		add_adressage(token, fd);
		add_param(head->next, fd, token);
		tmp = tmp->next;
	}
}