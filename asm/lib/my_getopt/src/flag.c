/*
** EPITECH PROJECT, 2017
** flag.c
** File description:
** <..>
*/

#include "my_getopt.h"

static char *create_flag(char ch)
{
	char	*s = (char *)malloc(sizeof(char) * 3);

	s[0] = '-';
	s[1] = ch;
	s[2] = '\0';
	return (s);
}

char *get_flag(char *str, int *x, const char *optstring)
{
	static int	current = 1;

	if (str[0] == '-' && len(str) > 2 && current < len(str)) {
		if (current+1 != len(str))
			*x -= 1;
		if (in_optstring(optstring, str[current])) {
			return (create_flag(str[current++]));
		} else {
			current++;
			return (dup_str(str+2));
		}
	} else {
		if (current == len(str))
			return (NULL);
		return (dup_str(str));
	}
}
