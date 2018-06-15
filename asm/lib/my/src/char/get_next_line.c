/*
** EPITECH PROJECT, 2017
** get_next_line.c
** File description:
** getting line
*/
#include "get_next_line.h"

int	choose(char *dest, char *str, int choice)
{
	int i = 0;

	if (choice == 1) {
		for (i = 0; str[i]; ++i)
			dest[i] = str[i];
		dest[i] = '\0';
	} else if (choice == 2) {
		for (i = 0; str && str[i]; ++i);
	} else {
		for (i = 0; str[i]; ++i) {
			if (str[i] == '\n')
				return (i);
		}
		return (-1);
	}
	return (i);
}

char	*my_rea_cat(char *str, char *buf, int *end)
{
	int	i = 0;
	char	*res = malloc(sizeof(char) *
		(choose(NULL, str, 2) + READ_SIZE) + 1);
	int	j = 0;

	if (res == NULL)
		return (NULL);
	for (i = 0; str && str[i]; ++i)
		res[i] = str[i];
	for (j = 0; buf[j] != '\n' && buf[j] != '\0'; ++i)
		res[i] = buf[j++];
	if (buf[j] == '\n')
		++j;
	if (buf[j - 1] == '\n')
		*end = 10;
	choose(buf, buf + j, 1);
	res[i] = 0;
	if (str != NULL)
		free(str);
	return (res);
}

int	filler(int *size, int *count, char **str, char *buf)
{
	if (*size != 0) {
		buf[*size] = 0;
		*size = 0;
	}
	if (choose(NULL, buf, 3) >= 0) {
		if (*count == 0)
			*str = my_rea_cat(*str, buf, count);
		return (1);
	}
	return (0);
}

char		*get_next_line(int fd)
{
	char		*str = NULL;
	static char	buf[READ_SIZE + 1];
	int		size = 0;
	int		count;

	while (42) {
		count = 0;
		if (choose(NULL, buf, 2) != 0) {
			count++;
			str = my_rea_cat(str, buf, &count);
			if (count == 10)
				return (str);
		}
		else if ((size = read(fd, buf, READ_SIZE)) <= 0)
			return (str);
		if (filler(&size, &count, &str, buf) == 1)
			return (str);
	}
	return (str);
}