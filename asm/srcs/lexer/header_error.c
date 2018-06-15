/*
** EPITECH PROJECT, 2017
** header_error.c
** File description:
** <..>
*/

#include "corewar.h"

header_t *catch_header_error(header_t *head, char *fname, int line_no)
{
	if (head->comment[0] == '\0')
		my_printf("asm, %s, line %d: Warning: No comment specified.\n",
				fname, line_no);
	if (head->prog_name[0] == '\0') {
		my_printf("asm, %s, line: %d: No name specified.\n", fname,
				line_no);
		exit(84);
	}
	return (head);
}

void catch_name(char *line, header_t *head, char *fname, int *line_no)
{
	int	i = 0;
	int	inc = 0;

	if (head->prog_name[0] != '\0')
		error_name(fname, *line_no);
	for (i = next_quote(line, 0) + 1, inc = 0; line[i] != '"'
			&& line[i]  && inc < PROG_NAME_LENGTH; i++, inc++)
		head->prog_name[inc]  = line[i];
	if (inc == PROG_NAME_LENGTH) {
		my_printf("asm, %s, line %d, The program name is too long.\n",
				fname, *line_no);
		exit(84);
	}
	if (line[i] == '\0' || is_noise(line + i + 1))
		syntax_error(fname, *line_no);
}

void comment_after_name_error(char *fname, int line_no)
{
	my_printf("asm, %s, line %d: The comment must be just after the name."
			"\n",
			fname, line_no);
	exit(84);
}

void name_on_first_line(char *fname, int line_no)
{
	my_printf("asm, %s, line %d: The name of your program "
			"must be the first line.\n", fname, line_no);
	exit(84);
}

void catch_comment(char *line, header_t *head, char *fname, int *line_no)
{
	int	i = 0;
	int	inc = 0;

	if (head->prog_name[0] == '\0') {
		my_printf("asm, %s, line %d: No name specified.\n", fname,
				*line_no);
		exit(84);
	}
	if (head->comment[0] != '\0')
		error_comment(fname, *line_no);
	for (i = next_quote(line, 0) + 1, inc = 0; line[i] != '"'
			&& line[i] && inc < COMMENT_LENGTH; i++, inc++)
		head->comment[inc]  = line[i];
	if (inc == COMMENT_LENGTH) {
		my_printf("asm, %s, line %d, The comment is too long.\n",
				fname, *line_no);
		exit(84);
	}
	if (line[i] == '\0' || is_noise(line + i + 1))
		syntax_error(fname, *line_no);
}