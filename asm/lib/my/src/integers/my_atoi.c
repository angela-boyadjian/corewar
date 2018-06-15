/*
** EPITECH PROJECT, 2017
** my_atoi.c
** File description:
** <..>
*/

#include "my.h"

int my_atoi(const char *nptr)
{
	long long int	no = 0;
	int		neg = 1;

	if (*nptr == '-')
		neg = ',' - *nptr++;
	while (*nptr != '\0') {
		if (*nptr <= '9' && *nptr >= '0') {
			no = (*nptr - '0') + (no * 10);
		} else {
			break;
		}
		nptr++;
	}
	no *= neg;
	return (no);
}