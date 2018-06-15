/*
** EPITECH PROJECT, 2017
** pu_in_me_two.c
** File description:
** pu_in_me_two_c_
*/

#include "virtual.h"

void cpy_mne_adr(char *tmp, int *i, instructions *list)
{
	char	*nb = malloc(sizeof(char) * 9);

	tmp[*i] = list->mnemonique[0];
	*i += 1;
	tmp[*i] = list->mnemonique[1];
	*i += 1;
	if (list->adr != 0) {
		dec_to_hexa(nb, list->adr);
		tmp[*i] = nb[0];
		*i += 1;
		tmp[*i] = nb[1];
		*i += 1;
	}
	free(nb);
}
