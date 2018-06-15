/*
** EPITECH PROJECT, 2017
** mem.c
** File description:
** <..>
*/

#include "corewar.h"

static int is_exception(struct token *node)
{
	char	*name[2] = { "live", NULL };

	for (int i = 0; name[i]; i++) {
		if (!my_strcmp(node->mnemo, name[i]))
			return (1);
	}
	return (0);
}
static int is_index(struct token *node)
{
	char	*name[4] = { "ldi", "sti", "lldi", NULL };

	for (int i = 0; name[i]; i++) {
		if (!my_strcmp(node->mnemo, name[i]))
			return (1);
	}
	return (0);
}

static int is_index_only(struct token *node)
{
	char	*name[4] = { "zjmp", "fork", "lfork", NULL };

	for (int i = 0; name[i]; i++) {
		if (!my_strcmp(node->mnemo, name[i]))
			return (1);
	}
	return (0);
}

static int add_arg(struct token *node)
{
	int	no = 0;

	for (int i = 0; i < node->arg_no; i++) {
		if (is_index_only(node) || (is_index(node) &&
					node->arg_tab[i].tk_name != REG)) {
			no += 2;
			continue;
		}
		if (node->arg_tab[i].tk_name == REG)
			no += T_REG;
		if (node->arg_tab[i].tk_name == DRT)
			no += DIR_SIZE;
		if (node->arg_tab[i].tk_name == IND)
			no+= IND_SIZE;
		if (node->arg_tab[i].tk_name == LAB)
			no += (node->arg_tab[i].args[0] == '%') ? DIR_SIZE :
				IND_SIZE;
	}
	return (no);
}

int set_mem(struct token *node, int flag)
{
	static int	curent_pos = 0;

	if (flag)
		return (curent_pos);
	if (node == NULL || node->tk_val == L)
		return (0);
	node->l_size = curent_pos;
	curent_pos += INSTRUCT_SIZE;
	if (is_exception(node)) {
		curent_pos += 4;
	} else {
		curent_pos += add_arg(node);
		curent_pos += (is_index_only(node)) ? 0 : 1;
	}
	return (curent_pos);
}
