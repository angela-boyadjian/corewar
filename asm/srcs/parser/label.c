/*
** EPITECH PROJECT, 2018
** label.c
** File description:
** functions to handle labels
*/
#include "corewar.h"

static void	undefined_label(struct token *token)
{
	my_printf(ERROR_MSG, token->fname, token->line,
	"Undefined label.\n");
	exit(FAILURE);
}

static struct d_queue	*get_label(char *label, struct d_queue *head)
{
	struct d_queue	*tmp = head;
	struct token	*token = tmp->token;

	while (tmp != NULL) {
		if (my_strcmp(token->mnemo, label) == SUCCESS
		&& token->tk_val == L && tmp->next != NULL) {
			return (tmp->next);
		} else if (my_strcmp(token->mnemo, label) == SUCCESS
		&& token->tk_val == L && tmp->next == NULL) {
			return (tmp);
		} else {
			tmp = tmp->next;
			if (!tmp)
				return (NULL);
			token = tmp->token;
		}

	}
	return (NULL);
}

static void	write_labels(int fd, struct token *token, int type,
union endian result)
{
	if (my_strcmp(token->mnemo, "live") == SUCCESS) {
		write(fd, &result, 4);
	} else if (check_case(token->mnemo) == true || type == VALID) {
		result.val = result.val >> 16;
		write(fd, &result, IND_SIZE);
	} else {
		write(fd, &result, DIR_SIZE);
	}
}

void	labels(struct d_queue *head, int fd, int i, struct token *token)
{
	union endian	result;
	int		curr = token->l_size;
	struct d_queue	*tmp;
	int		type = 0;
	struct	token	*tmp_tk = NULL;

	if (token->arg_tab[i].args[0] == '%')
		type = 2;
	else
		type = 1;
	tmp = get_label(token->arg_tab[i].args + type, head);
	if (!tmp)
		undefined_label(token);
	tmp_tk = tmp->token;
	result.val = tmp_tk->l_size - curr;
	swap_endian(&result);
	write_labels(fd, token, type, result);
}
