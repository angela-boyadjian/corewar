/*
** EPITECH PROJECT, 2017
** add_tree.c
** File description:
** add an element to a tree
*/

#include "clist.h"

struct tree *add_tree(struct tree *pos, void *value, enum branch branch)
{
	struct tree	*new = (struct tree *)malloc(sizeof(struct tree));
	struct tree	*tmp = pos;

	if (new == NULL)
		return (NULL);
	new->token = value;
	new->right = NULL;
	new->left = NULL;
	if (pos != NULL && branch == RIGHT)
		tmp->right = new;
	else if (pos != NULL && branch == LEFT)
		tmp->left = new;
	else
		tmp = new;
	return (tmp);
}
