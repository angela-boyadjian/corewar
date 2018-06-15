/*
** EPITECH PROJECT, 2018
** error.c
** File description:
** error handling
*/
#include "corewar.h"

static int	get_token(enum token_e tk_name)
{
	if (tk_name == REG)
		return (T_REG);
	else if (tk_name == DRT)
		return (T_DIR);
	return (T_IND);
}

static bool	is_valid_param(enum token_e tk_name, int index, int i)
{
	int	val;

	if (tk_name == LAB)
		return (true);
	val = get_token(tk_name);
	if ((val & op_tab[index].type[i]) > 0)
		return (true);
	return (false);
}

static int	check_param(struct token *token, int index)
{
	if (token->arg_no != op_tab[index].nbr_args)
		return (FAILURE);
	for (int i = 0; i < token->arg_no; ++i) {
		if (is_valid_param(token->arg_tab[i].tk_name, index, i)
		== false)
			return (FAILURE);
	}
	return (SUCCESS);
}

int	error_handling(struct token *token)
{
	int	index = get_cmd(token->mnemo);

	if (index == FAILURE && token->tk_val == I) {
		my_printf(ERROR_MSG, token->fname, token->line,
		"Invalid instruction.\n");
		exit(FAILURE);
	} else if (check_param(token, index) == FAILURE) {
		my_printf(ERROR_MSG, token->fname, token->line,
		"The argument given to the instruction is invalid.\n");
		exit(FAILURE);
	}
	return (SUCCESS);
}