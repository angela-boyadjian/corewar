/*
** EPITECH PROJECT, 2017
** my_getnbr.c
** File description:
** my_getnbr
*/

#include <unistd.h>
#include <stdio.h>

int my_getnbr(char *str)
{
	int	nb = 0;
	int	isneg = 1;
	int	i = 0;

	if (str[i] == '+' || str[i] == '-') {
		if (str[i] == '-')
			isneg = isneg * -1;
		i = i + 1;
	}
	while (str[i] != '\0' && nb < 2147483647) {
		if (str[i] >= '0' && str[i] <= '9') {
			nb = nb * 10;
			nb = nb + str[i] - '0';
			i++;
		} else
			return (nb * isneg);
	}
	return (nb * isneg);
}
