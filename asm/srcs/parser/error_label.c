/*
** EPITECH PROJECT, 2018
** error_label.c
** File description:
** error handling label
*/
#include "corewar.h"

int	is_valid_label(char *str)
{
	int	j;

	for (int i = 0; str[i]; ++i) {
		for (j = 0; LABEL_CHARS[j] && str[i] !=
		LABEL_CHARS[j]; ++j);
		if (LABEL_CHARS[j] == SUCCESS)
			return (FAILURE);
	}
	return (SUCCESS);
}

int	is_label_preceded(char *str)
{
	if (str[0] == LABEL_CHAR)
		return (SUCCESS);
	return (FAILURE);
}