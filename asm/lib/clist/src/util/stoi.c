/*
** EPITECH PROJECT, 2017
** stoi.c
** File description:
** <..>
*/

#include "clist.h"

int stoi(const char *nptr)
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
	if (no > 2147483647 || no < -2147483648)
		return (0);
	return (no);
}
