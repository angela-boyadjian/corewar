/*
** EPITECH PROJECT, 2017
** main.c
** File description:
** Arthur
*/

#include "virtual.h"
#include "printf.h"

void print_memory(char *memory)
{
	int	i = 0;

	my_putchar('\n');
	my_putstr("memory : ");
	while (i != my_strlen(memory)) {
		my_putchar(memory[i++]);
		my_putchar(' ');
	}
	my_putstr("\n\n");
}

int main(int ac, char **av)
{
	circular_memory	*vm = malloc(sizeof(circular_memory));
	champions	**champ = NULL;
	arg_champ	*av_list = NULL;

	if (ar_er(ac, av) > 0)
		return (84);
	if ((av_list = put_arg(ac, av)) == NULL)
		return (84);
	champ = malloc(sizeof(champions) * av_list->nbr_champ);
	if (champ == NULL)
		return (84);
	if (init_champions(champ, av_list) == 84)
		return (84);
	if (memory_init(vm, champ, av_list, MEM_SIZE) != 0)
		return (84);
	if (put_instructions_in_memory(champ, vm) == 84)
		return (84);
	print_memory(vm->memory);
	fight_loop(vm, champ);
	print_memory(vm->memory);
	return (0);
}
