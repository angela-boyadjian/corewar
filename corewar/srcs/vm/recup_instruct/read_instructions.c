/*
** EPITECH PROJECT, 2017
** read_instructions.c
** File description:
** recup_instructions_of_files
*/

#include "virtual.h"
#include "printf.h"

static int malloc_instruction(instructions *list)
{
	list->mnemonique = malloc(sizeof(char *));
	if (list->mnemonique == NULL)
		return (84);
	list->adr = 0;
	list->nb_cycles = 0;
	list->arg1 = 0;
	list->arg2 = 0;
	list->arg3 = 0;
	return (0);
}

static void init_instructions_tab(int (**inst_tab)(instructions *list, int fd))
{
	inst_tab[0] = &read_live;
	inst_tab[1] = &read_ld;
	inst_tab[2] = &read_st;
	inst_tab[3] = &read_add;
	inst_tab[4] = &read_sub;
	inst_tab[5] = &read_and;
	inst_tab[6] = &read_or;
	inst_tab[7] = &read_xor;
	inst_tab[8] = &read_zjmp;
	inst_tab[9] = &read_ldi_instruction;
	inst_tab[10] = &read_sti_instruction;
	inst_tab[11] = &read_fork;
	inst_tab[12] = &read_lld;
	inst_tab[13] = &read_lldi;
	inst_tab[14] = &read_lfork;
	inst_tab[15] = &read_aff;
}

static void	display(instructions *tmp_list)
{
	my_printf("==> %s", tmp_list->mnemonique);
	my_printf("	/ TY = %d", tmp_list->types);
	my_printf("	/ AD = %X", tmp_list->adr);
	my_printf("	/ A1 = %X", tmp_list->arg1);
	my_printf("	/ A2 = %X", tmp_list->arg2);
	my_printf("	/ A3 = %X\n", tmp_list->arg3);
}

instructions *read_instructions(int fd, instructions *list)
{
	int			rv = 0;
	int			i = 0;
	instructions		*tmp_list = list;
	int			(*inst_tab[16])(instructions *list, int fd);

	my_printf("\n == instructions == \n\n");
	init_instructions_tab(inst_tab);
	while ((rv = read(fd, &i, 1)) != 0) {
		if (malloc_instruction(tmp_list) == 84)
			return (NULL);
		if (inst_tab[i - 1](tmp_list, fd) == -1)
			return (NULL);
		if ((tmp_list->next = malloc(sizeof(instructions))) == NULL)
			return (NULL);
		display(tmp_list);
		tmp_list = tmp_list->next;
	}
	tmp_list->next = NULL;
	return (list);
}
