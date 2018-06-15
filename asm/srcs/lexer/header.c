/*
** EPITECH PROJECT, 2017
** header.c
** File description:
** <..>
*/

#include "corewar.h"

static void set_zero(header_t *head)
{
	my_memset(head, 0, sizeof(header_t));
	head->magic = COREWAR_EXEC_MAGIC;
	head->prog_size = 0;
	for (int i = 0; i < PROG_NAME_LENGTH + 1; i++)
		head->prog_name[i] = '\0';
	for (int i = 0; i < COMMENT_LENGTH + 1; i++)
		head->comment[i] = '\0';
}

static int is_name(char *line)
{
	char	name[6] = ".name\0";
	int	i = 0;
	int	ind = 0;

	while ((line[ind] == ' ' || line[ind] == '\t') && line[ind] != '\0')
		ind++;
	for (i = ind; i < ind + 5; i++) {
		if (line[i] != name[i - ind])
			break;
	}
	if (i == ind + 5)
		return (i);
	return (0);
}

static int is_comment(char *line)
{
	char	name[9] = ".comment\0";
	int	i = 0;
	int	ind = 0;

	while ((line[ind] == ' ' || line[ind] == '\t') && line[ind] != '\0')
		ind++;
	for (i = ind; i < ind + 8; i++) {
		if (line[i] != name[i - ind])
			break;
	}
	if (i == ind + 8)
		return (i);
	return (0);
}

static void get_header(char *line, header_t *head, char *fname, int *line_no)
{
	static int	name_var = 0;
	static int	text_var = 0;

	if (is_name(line)) {
		if (text_var == 1)
			name_on_first_line(fname, *line_no);
		catch_name(line, head, fname, line_no);
		name_var = 1;
		return;
	}
	if (is_comment(line)) {
		if (!name_var)
			comment_after_name_error(fname, *line_no);
		catch_comment(line, head, fname, line_no);
		return;
	}
	if (is_label(line) || is_mnemonic(line))
		text_var = 1;
}

header_t *create_header(int fd, char *line, char *fname, int line_no)
{
	header_t	*head = (header_t *)malloc(sizeof(header_t));

	if (head == NULL)
		return (NULL);
	set_zero(head);
	line = get_next_line(fd);
	while (line) {
		line_no += 1;
		if (!is_line_comment(line))
			get_header(line, head, fname, &line_no);
		if (head->prog_name[0] != '\0' && head->comment[0] != '\0') {
			free(line);
			break;
		}
		free(line);
		line = get_next_line(fd);
	}
	lseek(fd, 0, SEEK_SET);
	return (catch_header_error(head, fname, line_no));
}
