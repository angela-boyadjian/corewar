/*
** EPITECH PROJECT, 2017
** my_fgets.c
** File description:
** the fgets function
*/

#include "my_fgets.h"

static char my_getchar_fd(unsigned int stream)
{
	char	ch = 0;
	int	rt = 0;

	rt = read(stream, &ch, 1);
	if (rt == 0)
		return (-1);
	return (ch);
}

char *my_fgets(char *s, int size, unsigned int stream)
{
	int	i = 0;
	char	ch = 1;

	if (s == NULL)
		return (NULL);
	while (i < size)
		s[i++] = 0;
	i = 0;
	while (i < size && ch != '\n') {
		ch = my_getchar_fd(stream);
		if (ch == -1)
			return (NULL);
		s[i++] = ch;
	}
	s[i - 1] = '\0';
	return (s);
}
