/*
** EPITECH PROJECT, 2017
** skip.c
** File description:
** <..>
*/

#include "corewar.h"

int skip_tabs(char *line)
{
	int	i = 0;

	while (line[i] != '"' && line[i] != '\0')
		i++;
	return (i);
}

int next_quote(char *line, int inc)
{
	int	i = 0;

	while (line[i] != '"' && line[i] != '\0')
		i++;
	return (i + inc);
}

int skip_space_tabs(char *line)
{
	int	i = 0;

	while ((line[i] == '\t' || line[i] == ' ') && line[i] != '\0')
		i++;
	return (i);
}

int skip_space_tabs_arg(char *line)
{
	int	i = 0;

	while ((line[i] == '\t' || line[i] == ' ' ||
			line [i] == SEPARATOR_CHAR) && line[i] != '\0')
		i++;
	return (i);
}

int skip_space_tabs_lab(char *line)
{
	int	i = 0;

	while ((line[i] == '\t' || line[i] == ' ' ||
			line [i] == LABEL_CHAR) && line[i] != '\0')
		i++;
	return (i);
}
