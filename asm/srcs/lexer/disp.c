/*
** EPITECH PROJECT, 2017
** disp.c
** File description:
** <..>
*/

#include "corewar.h"

void disp(struct token *node)
{
	if (!node)
		return;
	my_printf("-----------------------------------------------------\n");
	my_printf("%s: ", (node->tk_val == L) ? "label" : "mnemo");
	my_printf("%s\n", node->mnemo);
	my_printf("Argno: %d\n", node->arg_no);
	for (int i = 0; i < node->arg_no; i++) {
		my_printf("[%d] = %s | ", i, node->arg_tab[i].args);
		if (node->arg_tab[i].tk_name == REG)
			my_printf("register");
		if (node->arg_tab[i].tk_name == DRT)
			my_printf("direct");
		if (node->arg_tab[i].tk_name == IND)
			my_printf("indirect");
		if (node->arg_tab[i].tk_name == LAB)
			my_printf("label");
		my_printf(" %d\n", node->arg_tab[i].tk_name);
	}
	my_printf("line_pos: %d, instruct_size: %d\n", node->line,
			node->l_size);
}
