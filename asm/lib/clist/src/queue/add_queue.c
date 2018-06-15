/*
** EPITECH PROJECT, 2017
** add_queue.c
** File description:
** <..>
*/

#include "clist.h"

struct queue *add_queue(struct queue *root, void *value)
{
	struct queue	*new = (struct queue *)malloc(sizeof(struct queue));
	struct queue	*tmp = root;

	if (new == NULL)
		return (NULL);
	new->token = value;
	new->next = NULL;
	if (root == NULL)
		return (new);
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
	return (root);
}
