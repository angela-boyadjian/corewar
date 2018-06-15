/*
** EPITECH PROJECT, 2017
** convert.c
** File description:
** converteur
*/

#include <stdlib.h>

char *my_revstr(char *str);

int cti(char c)
{
	int	nb = c - 48;

	return (nb);
}

char itc(int nb)
{
	char	c = nb + 48;

	return (c);
}

char *its(int nb, char *str)
{
	char	base[10] = "0123456789";
	int	i = 0;
	int	j = 0;
	int	tmp = 0;

	while (nb != 0) {
		tmp = nb % 10;
		nb = nb / 10;
		while (base[j] != '\0' && itc(tmp) != base[j] - 48)
			++j;
		str[i] = base[j] - 48;
		j = 0;
		++i;
	}
	str[i] = '\0';
	my_revstr(str);
	return (str);
}
