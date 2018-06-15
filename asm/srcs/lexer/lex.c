/*
** EPITECH PROJECT, 2017
** lex.c
** File description:
** lexer file
*/

#include "corewar.h"

static struct token *proccess_label(char *line ,int *pos, struct token *node)
{
	while ((line[*pos] == ' ' || line[*pos] == '\t') && line[*pos] != '\0')
		*pos += 1;
	node->tk_val = L;
	node->mnemo = my_strndup(line + *pos, is_label(line + *pos));
	node->l_size = set_mem(node, 1);
	*pos += is_label(line + *pos);
	*pos += skip_space_tabs_lab(line + *pos);
	node->arg_tab = NULL;
	node->arg_no = 0;
	return (node);
}

static struct token *proccess_mnemonique(char *line ,struct token *node,
		int *pos)
{
	int	i = 0;

	*pos += skip_space_tabs(line + *pos);
	node->tk_val = I;
	if (is_mnemonic(line + *pos) == 0)
		return (NULL);
	node->mnemo = my_strndup(line + *pos, is_mnemonic(line + *pos));
	*pos += is_mnemonic(line + *pos) + 1;
	node->arg_no = (*pos < my_strlen(line)) ? count_arg(line + *pos) : 0;
	node->arg_tab = malloc(sizeof(struct args_s) * node->arg_no + 1);
	for (i = 0; i < node->arg_no; i++) {
		*pos += skip_space_tabs(line + *pos);
		node->arg_tab[i].args = my_strndup(line + *pos,
				is_arg(line + *pos));
		node->arg_tab[i].tk_name = get_arg_type(line + *pos);
		*pos += is_arg(line + *pos);
		*pos += skip_space_tabs_arg(line + *pos);
	}
	set_mem(node, 0);
	return (node);
}

static struct token *process_line(char *line, int line_no, char *fname,
		int *pos)
{
	struct token	*node = malloc(sizeof(struct token));

	if (node == NULL)
		malloc_error();
	my_memset(node, 0, sizeof(struct token));
	if (is_line_comment(line + *pos) || my_strlen(line) == 0 ||
			is_header(line + *pos)) {
		*pos = my_strlen(line);
		free(node);
		return (NULL);
	}
	node->fname = my_strdup(fname);
	node->line = line_no;
	if (is_label(line + *pos)) {
		node = proccess_label(line, pos, node);
	} else {
		if (proccess_mnemonique(line , node, pos) == NULL)
			error_invalid_instruct(fname, line_no);
	}
	return (node);
}

static struct d_queue *set_size(struct d_queue * head)
{
	header_t	*header = NULL;
	if (head == NULL)
		return (NULL);
	header = head->token;
	header->prog_size = set_mem(NULL, 1);
	return (head);
}

struct d_queue *lex_file(char *fname)
{
	int		fd = open(fname, O_RDONLY);
	int		line_no = 0;
	struct token	*node = NULL;
	struct d_queue	*tmp = NULL;
	char		*line = NULL;

	if (fd < 0)
		return (file_error(fname));
	tmp = add_d_queue(tmp, create_header(fd, line, fname, line_no));
	line = get_next_line(fd);
	while (line) {
		for (int pos = 0; pos < my_strlen(line);) {
			node = process_line(line, line_no, fname, &pos);
			tmp = (node) ? add_d_queue(tmp, (void *)node) : tmp;
		}
		++line_no;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (set_size(tmp));
}
