/*
** EPITECH PROJECT, 2017
** string.c
** File description:
** basic string processing functions
*/

#include "corewar.h"

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
		return (1);
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
		return (1);
	return (0);
}

int is_line_comment(char *line)
{
	int	i = 0;

	while ((line[i] == ' ' || line[i] == '\t') && line[i] != '\0')
		i++;
	if (line != NULL && (line[i] == '#' || line [i] == '\0'))
		return (i + 1);
	return (0);
}

int is_header(char *line)
{
	if (line != NULL && is_name(line))
		return (1);
	if (line != NULL && is_comment(line))
		return (2);
	return (0);
}
