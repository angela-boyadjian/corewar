/*
** EPITECH PROJECT, 2017
** my_printf.c
** File description:
** the printf function
*/

#include "my_printf.h"

static int get_arg(char ch)
{
	char	*larg = "sSidcouxXbpRn";
	int	i = 0;

	while (larg[i] != '\0') {
		if (ch == larg[i])
			return (i);
		++i;
	}
	return (-1);
}

static char *get_flag_arg(char **f)
{
	char	*arg = 0;
	int	len = 0;
	int	i = 0;

	while ((is_digit(f[0][len]) || is_char(f[0][len]) || f[0][len] == '#'
			|| f[0][len] == ' ') && (get_arg(f[0][len]) < 0)) {
		len++;
	}
	if (++len == 1)
		return (NULL);
	arg = (char *)malloc(sizeof(char) * (len + 1));
	while (i < len) {
		arg[i] = f[0][i];
		i += 1;
	}
	arg[i] = '\0';
	*f += (i - 1);
	return (arg);
}

static int vprintf_flag(va_list arg, char **f)
{
	int	(*fp[])(va_list, char *) = { &my_printf_s, &my_printf_bs,
			&my_printf_i, &my_printf_d, &my_printf_c, &my_printf_o,
			&my_printf_u, &my_printf_x, &my_printf_bx,
			&my_printf_b, &my_printf_p, &my_printf_br,
			&my_printf_n, 0 };
	char	*flag_arg = get_flag_arg(f);

	if (get_arg(**f) >= 0) {
		fp[get_arg(**f)](arg, flag_arg);
	} else {
		if (**f != '%')
			my_putchar('%');
		my_putchar(**f);
	}
	*f += 1;
	return (0);
}

int my_v_printf(char *fm, va_list arg)
{
	while (*fm != '\0') {
		if (*fm == '%') {
			fm++;
			vprintf_flag(arg, &fm);
		} else {
			my_putchar(*(fm)++);
		}
	}
	return (0);
}

int my_printf(const char *format, ...)
{
	va_list	args;
	char	*buffer = my_strdup(format);

	my_print_write_count = 0;
	va_start(args, format);
	my_v_printf(buffer, args);
	va_end(args);
	return (my_print_write_count);
}
