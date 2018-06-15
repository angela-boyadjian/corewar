/*
** EPITECH PROJECT, 2017
** init_vm.c
** File description:
** init_vm_c_
*/

#include "virtual.h"

int adr_acc(int adr)
{
	if (adr > 0)
		--adr;
	else
		++adr;
	return (adr);
}

int set_flag(int adr)
{
	int	flag = 0;

	if (adr > 0)
		flag = 1;
	else if (adr < 0)
		flag = -1;
	return (flag);
}

void memory_memset(char *memory, int size)
{
	int	i = 0;

	while (i != size)
		memory[i++] = '0';
	memory[i] = '\0';
}

void memory_put_move(circular_memory *vm, champions *champ, char data, int adr)
{
	int	flag = 0;
	int	flag2 = 0;

	if (adr > 0)
		flag2 = 1;
	flag = set_flag(adr);
	while (adr != 0) {
		if (champ->tmp == vm->memory_end) {
			champ->tmp = vm->memory_head;
		} else if (champ->tmp == vm->memory_head - flag2)
			champ->tmp = vm->memory_end;
		champ->tmp += flag;
		adr = adr_acc(adr);
	}
	if (data != ' ')
		*champ->tmp = data;
}

int memory_init(circular_memory *vm, champions **champ, arg_champ *av_list,
int size)
{
	if (do_malloc(vm, champ, size) == -1)
		return (-1);
	vm->nbr_live = 0;
	memory_memset(vm->memory, size);
	vm->memory_end = vm->memory + (size - 1);
	vm->memory_head = vm->memory;
	for (int i = 0; av_list != NULL; ++i) {
		champ[i]->PC = vm->memory;
		champ[i]->tmp = champ[i]->PC;
		if (av_list->hyp_a == 0) {
			memory_put_move(vm, champ[i], ' ', MEM_SIZE /
					(av_list->nbr_champ * (i + 1)) - 1);
		} else
			memory_put_move(vm, champ[i], ' ', av_list->hyp_a);
		champ[i]->PC = champ[i]->tmp;
		av_list = av_list->next;
	}
	vm->size = size;
	return (0);
}