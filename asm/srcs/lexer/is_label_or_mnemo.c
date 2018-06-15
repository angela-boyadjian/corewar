/*
** EPITECH PROJECT, 2017
** string2.c
** File description:
** <..>
*/

#include "corewar.h"

static int is_label_char(char ch)
{
	char	*label_char = my_strdup(LABEL_CHARS);

	for (int i = 0; label_char[i]; i++) {
		if (label_char[i] == ch) {
			free(label_char);
			return (1);
		}
	}
	free(label_char);
	return (0);
}

int is_label(char *line)
{
	int	i = 0;

	while ((line[i] == ' ' || line[i] == '\t') && line[i] != '\0')
		i++;
	while (line[i] != '\0') {
		if (line[i] == LABEL_CHAR)
			return (i);
		if (is_label_char(line[i]) == 0)
			return (0);
		++i;
	}
	return (0);
}

int is_mnemonic(char *line)
{
	int	i = 0;

	while ((line[i] == ' ' || line[i] == '\t') && line[i] != '\0')
		i++;
	while (line[i] != '\0') {
		if (line[i] == ' ' || line[i] == '\t')
			return (i);
		++i;
	}
	return (i);
}

int count_arg(char *line)
{
	int	count = 0;

	for (int i = 0; line && line[i]; i++) {
		if (line[i] == SEPARATOR_CHAR)
			count++;
	}
	return (count + 1);
}

int is_arg(char *line)
{
	int	i = 0;

	while ((line[i] == ' ' || line[i] == '\t') && line[i] != '\0')
		i++;
	while (line[i] != '\0') {
		if (line[i] == SEPARATOR_CHAR)
			return (i);
		if (line[i] == COMMENT_CHAR)
			return (i);
		if (line [i] == ' ' || line[i] == '\t')
			return (i);
		++i;
	}
	return (i);
}