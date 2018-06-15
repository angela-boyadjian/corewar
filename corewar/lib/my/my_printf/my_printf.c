/*
** EPITECH PROJECT, 2017
** my_printf.c
** File description:
** printf
*/

#include "../../../include/my.h"
#include "../../../include/printf.h"
#include <stdio.h>

static int str_parser(char flag)
{
	int	i = 0;
	char	*str = "sdicuxXopbS%";

	while (str[i] != flag && str[i] != '\0') {
		i++;
	}
	if (str[i] == '\0')
		return (84);
	else
		return (i);
}

static void my_init(int (*PointeursurFonction[12])(va_list ap))
{
	PointeursurFonction[0] = &case_s;
	PointeursurFonction[1] = &case_d;
	PointeursurFonction[2] = &case_d;
	PointeursurFonction[3] = &case_c;
	PointeursurFonction[4] = &case_u;
	PointeursurFonction[5] = &case_x;
	PointeursurFonction[6] = &case_xmaj;
	PointeursurFonction[7] = &case_o;
	PointeursurFonction[8] = &case_p;
	PointeursurFonction[9] = &case_b;
	PointeursurFonction[10] = &case_smaj;
	PointeursurFonction[11] = &case_mod;
}

int my_printf(char const *str, ...)
{
	va_list	ap;
	int	(*PointeursurFonction[12])(va_list ap);
	int	j;

	va_start(ap, str);
	my_init(PointeursurFonction);
	for (int i = 0; str[i]; i++) {
		if (str[i] != '%')
			my_putchar(str[i]);
		else {
			i++;
			j = str_parser(str[i]);
			PointeursurFonction[j](ap);
		}
	}
	va_end(ap);
	return (0);
}
