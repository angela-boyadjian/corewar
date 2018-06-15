/*
** EPITECH PROJECT, 2017
** put_instru_in_memory.c
** File description:
** put_instru_in_memory_c_
*/

#include "virtual.h"
#include "printf.h"

void dec_to_hexa(char *tmp, int value)
{
	int	i = 0;
	int	j = 0;

	j = value;
	if (j != 2 || j != 4 || j != 8)
		j = 0;
	while (value != 0) {
		tmp[i] = value % 16;
		if (tmp[i] > 9)
			tmp[i++] += 55;
		else
			tmp[i++] += 48;
		value /= 16;
	}
	while (i < j)
		tmp[i++] = '0';
	tmp[i] = '\0';
	my_revstr(tmp);
}

void cpy_dec(char *tmp, int *i, char *nb)
{
	int	j = 0;

	while (nb[j] != '\0') {
		tmp[*i] = nb[j];
		*i += 1;
		++j;
	}
}

void instruction_str(char *tmp, instructions *list)
{
	int	i = 0;
	char	*nb = malloc(sizeof(char) * 9);

	cpy_mne_adr(tmp, &i, list);
	dec_to_hexa(nb, list->types / 100);
	cpy_dec(tmp, &i, nb);
	if (list->arg2 != 0) {
		dec_to_hexa(nb, list->types / 10 % 10);
		cpy_dec(tmp, &i, nb);
	}
	if (list->arg3 != 0) {
		dec_to_hexa(nb, list->types % 10);
		cpy_dec(tmp, &i, nb);
	}
	tmp[i] = '\0';
	my_printf("== instructions str ==> %s\n", tmp);
}

instructions *put_champ_in_mem(champions *champ, circular_memory *vm)
{
	char		*tmp = malloc(sizeof(char) * 20);
	instructions	*tmp_list = champ->list;
	int		i = 0;

	if (tmp == NULL)
		return (NULL);
	my_printf("\n");
	while (champ->list->next != NULL) {
		instruction_str(tmp, champ->list);
		while (tmp[i] != '\0')
			memory_put_move(vm, champ, tmp[i++], 1);
		i = 0;
		champ->list = champ->list->next;
	}
	++champ->PC;
	champ->end = champ->tmp;
	champ->tmp = champ->PC;
	return (tmp_list);
}

int put_instructions_in_memory(champions **champ, circular_memory *vm)
{
	int	i = 0;

	while (champ[i] != NULL) {
		if ((champ[i]->list = put_champ_in_mem(champ[i], vm)) == NULL)
			return (84);
		++i;
	}
	return (0);
}
