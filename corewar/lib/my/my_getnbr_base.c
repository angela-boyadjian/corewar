/*
** EPITECH PROJECT, 2017
** my_getnbr_base.c
** File description:
** getnbr base
*/

int my_strlen(char const *str);
int my_compute_power_rec(int nb, int p);

static int from_base(char c, char const *base)
{
	int	i;

	for (i = 0; base[i] && base[i] != c; ++i);
	if (base[i] == 0)
		return (-1);
	return (i);
}

static int negative(char const *str)
{
	int	check = 1;
	int	i = 0;

	while (str[i]) {
		if (str[i] == '-')
			check *= -1;
		++i;
	}
	return (check);
}

int my_getnbr_base(char const *str, char const *base)
{
	int	i = 0;
	int	base_size = my_strlen(base);
	int	nbr_size = 0;
	int	result = 0;

	for (; str[i] && (str[i] == '+' || str[i] == '-'); ++i);
	nbr_size = my_strlen(str + i) - 1;
	while (str[i]) {
		if (from_base(str[i], base) < 0)
			return (0);
		result += my_compute_power_rec(base_size, nbr_size--)
		* from_base(str[i++], base);
	}
	return (result * negative(str));
}
