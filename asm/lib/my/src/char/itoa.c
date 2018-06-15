/*
** EPITECH PROJECT, 2017
** itoa.c
** File description:
** <..>
*/

#include "my.h"

char *my_itoa(int no)
{
	char	*buf = (char *)malloc(sizeof(char) * number_len(no) + 1);
	int	i = 0;

	while (i < number_len(no)) {
		buf[i] = get_digit(no, number_len(no) - (i + 1)) + '0';
		++i;
	}
	buf[i] = '\0';
	return (buf);
}
