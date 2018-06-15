/*
** EPITECH PROJECT, 2017
** my_strstr.c
** File description:
** Find a string inside of an other string
*/

#include "my.h"

static int get_len_str(char const *str)
{
	int	len = 0;

	while (*(str + len) != '\0')
		len++;
	return (len);
}

static int find_occurence(char *p_begining_occurence, char const *to_find)
{
	int	len = get_len_str(to_find);
	int	i = 0;

	while (*(p_begining_occurence + i) == *(to_find + i) && i < len) {
		i++;
	}
	if (i == len)
		return (1);
	else
		return (0);
}

char *my_strstr(char *src, char const *to_find)
{
	int	len = get_len_str(src);
	int	i = 0;

	if (src == 0 || to_find == 0)
		return (0);
	while (*src != '\0') {
		if (find_occurence(src, to_find))
			break;
		src++;
		i++;
	}
	if (i == len)
		return (0);
	else
		return (src);
}
