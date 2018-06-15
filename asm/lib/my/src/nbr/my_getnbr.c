/*
** EPITECH PROJECT, 2017
** my_getnbr
** File description:
** my_getnbr ex.
*/

#include "my.h"

int my_getnbr(char *str)
{
	long long int	no = 0;
	int		neg = 1;

	if (*str == '-')
		neg = ',' - *str++;
	while (*str != '\0') {
		if (*str <= '9' && *str >= '0') {
			no = (*str - '0') + (no * 10);
		} else {
			break;
		}
		str++;
	}
	no *= neg;
	return (no);
}
