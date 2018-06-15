/*
** EPITECH PROJECT, 2018
** adressage.c
** File description:
** functions to do the adressage
*/
#include "corewar.h"

static void	handle_lab(struct token *token, int *result, int i)
{
	if (token->arg_tab[i].args[0] == '%') {
		*result += 2;
		*result = *result << 2;
	} else {
		*result += 3;
		*result = *result << 2;
	}
}

static void	add_args(struct token *token, int *result, int i)
{
	if (token->arg_tab[i].tk_name == REG) {
		*result += 1;
		*result = *result << 2;
	}
	if (token->arg_tab[i].tk_name == DRT) {
		*result += 2;
		*result = *result << 2;
	}
	if (token->arg_tab[i].tk_name == IND) {
		*result += 3;
		*result = *result << 2;
	}
	if (token->arg_tab[i].tk_name == LAB)
		handle_lab(token, result, i);
}

static int	adressage(struct token *token)
{
	int	result = 0;

	result = result << 2;
	for (int i = 0; i < 3; ++i) {
		if (i < token->arg_no)
			add_args(token, &result, i);
		else
			result = result << 2;
	}
	return (result);
}

static bool	check_exception(char *str)
{
	if (my_strcmp(str, "zjmp") == 0 || my_strcmp(str, "live") == 0 ||
	my_strcmp(str, "lfork") == 0 || my_strcmp(str, "fork") == 0)
		return (true);
	return (false);
}

void	add_adressage(struct token *token, int fd)
{
	int	result;

	if (check_exception(token->mnemo) == true || token->tk_val == L)
		return;
	result = adressage(token);
	write(fd, &result, 1);
}