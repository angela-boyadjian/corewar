/*
** EPITECH PROJECT, 2017
** pop_tree.c
** File description:
** remove element from tree
*/

#include "clist.h"

void *pop_tree(struct tree *pos, enum branch branch)
{
	void	*tmp_token = NULL;

	if (pos == NULL)
		return (NULL);
	if (branch == RIGHT) {
		if (pos->right == NULL)
			return (NULL);
		tmp_token = pos->right->token;
		free(pos->right);
		pos->right = NULL;
	} else if (branch == LEFT) {
		if (pos->left == NULL)
			return (NULL);
		tmp_token = pos->left->token;
		free(pos->left);
		pos->left = NULL;
	} else {
		tmp_token = pos->token;
		free(pos);
	}
	return (tmp_token);
}
