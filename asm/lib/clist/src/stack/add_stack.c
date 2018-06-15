/*
** EPITECH PROJECT, 2017
** add_stack.c
** File description:
** add an element to the stack
*/

#include "clist.h"

struct stack *add_stack(struct stack *root, void *value)
{
	struct stack *tmp_root = (struct stack *)malloc(sizeof(struct stack));

	if (tmp_root == NULL)
		return (NULL);
	tmp_root->token = value;
	tmp_root->next = root;
	return (tmp_root);
}
