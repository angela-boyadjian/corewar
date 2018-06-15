/*
** EPITECH PROJECT, 2017
** read_headers.c
** File description:
** read_headers_files_with_error_handling
*/

#include "virtual.h"

int headers_error_handling(struct header_s *files_h)
{
	if (files_h->magic != 15369203)
		return (-1);
	else if (my_strlen(files_h->prog_name) > PROG_NAME_LENGTH
			|| my_strlen(files_h->prog_name) == 0)
		return (-1);
	if (my_strlen(files_h->comment) > COMMENT_LENGTH ||
			my_strlen(files_h->comment) == 0)
		return (-1);
	return (0);
}

int read_headers(instructions *list, int fd)
{
	struct header_s	*files_h = NULL;
	union endian	tmp;

	if ((files_h = malloc(sizeof(struct header_s))) == NULL)
		return (-1);
	if ((read(fd, files_h, sizeof(struct header_s))) == -1)
		return (-1);
	tmp.val = files_h->magic;
	switch_endian_four(&tmp);
	files_h->magic = tmp.val;
	tmp.val = files_h->prog_size;
	switch_endian_four(&tmp);
	files_h->prog_size = tmp.val;
	if (headers_error_handling(files_h) != 0)
		return (-1);
	list->name = malloc(sizeof(char) * (my_strlen(files_h->prog_name) + 1));
	my_strcpy(list->name, files_h->prog_name);
	return (0);
}
