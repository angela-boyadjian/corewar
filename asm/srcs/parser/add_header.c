/*
** EPITECH PROJECT, 2018
** header.c
** File description:
** functions to write header functions
*/
#include "corewar.h"

void	add_header(struct d_queue *head, int fd)
{
	struct header_s	*header = head->token;
	union endian	result;

	result.val = header->magic;
	swap_endian(&result);
	header->magic = result.val;
	result.val = header->prog_size;
	swap_endian(&result);
	header->prog_size = result.val;
	write(fd, head->token, sizeof(struct header_s));
}
