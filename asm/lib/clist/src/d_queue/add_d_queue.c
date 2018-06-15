/*
** EPITECH PROJECT, 2017
** add_d_queue.c
** File description:
** <..>
*/

#include "clist.h"

struct d_queue *add_d_queue(struct d_queue *root, void *value)
{
	struct d_queue	*new = (struct d_queue *)malloc(sizeof(struct d_queue));
	struct d_queue	*tmp = root;

	if (new == NULL)
		return (NULL);
	new->token = value;
	new->next = NULL;
	new->back = NULL;
	if (root == NULL)
		return (new);
	while (tmp->next != NULL)
		tmp = tmp->next;
	new->back = tmp;
	tmp->next = new;
	return (root);
}
