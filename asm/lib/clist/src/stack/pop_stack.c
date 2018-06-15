/*
** EPITECH PROJECT, 2017
** pop_stack.c
** File description:
** pop the value that is on the top of the stack
*/

#include "clist.h"

void *pop_stack(struct stack **root)
{
	void		*temp_value = NULL;
	struct stack	*tmp_addr = NULL;

	if (root != NULL && *root != NULL) {
		temp_value = (*root)->token;
		tmp_addr = *(root);
		*(root) = (*root)->next;
		free(tmp_addr->token);
		free(tmp_addr);
		return (temp_value);
	} else {
		return (NULL);
	}
}
