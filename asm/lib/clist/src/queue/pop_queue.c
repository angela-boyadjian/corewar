/*
** EPITECH PROJECT, 2017
** pop_queue.c
** File description:
** <..>
*/

#include "clist.h"

void *pop_queue(struct queue *root)
{
	struct queue	*tmp;
	struct queue	*before;
	void		*token;

	if (root == NULL)
		return (NULL);
	tmp = root;
	before = tmp;
	while (tmp->next) {
		before = tmp;
		tmp = tmp->next;
	}
	before->next = NULL;
	token = tmp->token;
	free(tmp);
	return (token);
}
