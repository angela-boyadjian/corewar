/*
** EPITECH PROJECT, 2017
** arg_champ.c
** File description:
** Arthur
*/

#include "virtual.h"

void insert_nbr_champ(arg_champ **first_elem, int nbr)
{
	arg_champ	*actual = (*first_elem);

	while (actual != NULL) {
		actual->nbr_champ = nbr;
		actual = actual->next;
	}
}

arg_champ *init_ag_champ(int hyp_a, int hyp_n, char *av)
{
	arg_champ	*element = malloc(sizeof(arg_champ));

	if (element == NULL)
		return (NULL);
	element->nbr_champ = 0;
	element->hyp_a = hyp_a % MEM_SIZE;
	element->hyp_n = hyp_n;
	element->cor = av;
	element->next = NULL;
	return (element);
}

int insert_begin(arg_champ **first_elem, int hyp_a, int hyp_n, char *av)
{
	arg_champ	*new_elem = malloc(sizeof(arg_champ));

	if (new_elem == NULL)
		return (84);
	new_elem->nbr_champ = 0;
	new_elem->hyp_a = hyp_a % MEM_SIZE;
	new_elem->hyp_n = hyp_n;
	new_elem->cor = av;
	new_elem->next = *first_elem;
	(*first_elem) = new_elem;
	return (0);
}

int insert_end(arg_champ **first_elem, int hyp_a, int hyp_n, char *av)
{
	arg_champ	*new_elem = malloc(sizeof(arg_champ));
	arg_champ	*actual = (*first_elem);

	if (new_elem == NULL)
		return (84);
	new_elem->nbr_champ = 0;
	new_elem->hyp_a = hyp_a % MEM_SIZE;
	new_elem->hyp_n = hyp_n;
	new_elem->cor = av;
	new_elem->next = NULL;
	while (actual->next != NULL)
		actual = actual->next;
	actual->next = new_elem;
	return (0);
}

int	do_malloc(circular_memory *vm, champions **champ, int size)
{
	if ((vm->memory = malloc(sizeof(char) * (size + 2))) == NULL)
		return (-1);
	if ((vm->champ_name = malloc(sizeof(char *) * 5)) == NULL)
		return (-1);
	if (save_id(vm->champ_name, champ) == -1)
		return (-1);
	return (0);
}