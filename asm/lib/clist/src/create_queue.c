/*
** EPITECH PROJECT, 2017
** create_queue.c
** File description:
** create a queue from a string using separatos
*/

#include "clist.h"

struct queue *create_queue(const char *str, const char **sep, size_t type)
{
	struct queue	*tmp = (struct queue *)malloc(sizeof(struct queue));

	if (tmp == NULL || str == NULL || sep == NULL || type == 0)
		return (NULL);
}
