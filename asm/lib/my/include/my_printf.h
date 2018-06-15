/*
** EPITECH PROJECT, 2017
** my_printf.h
** File description:
** the printf header file
*/

#ifndef MY_PRINTF_H_
#define MY_PRINTF_H_

#include "my.h"
#include <stdarg.h>
#include <stdio.h>

#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KBLU  "\x1B[34m"
#define KCYN  "\x1B[36m"

int my_print_write_count;

int my_printf(const char *, ...);
int my_v_printf(char *, va_list);
int my_printf_bs_padding(int);
int my_printf_d_padding(int, char *);
int my_printf_s(va_list, char *);
int my_printf_bs(va_list, char *);
int my_printf_i(va_list, char *);
int my_printf_c(va_list, char *);
int my_printf_d(va_list, char *);
int my_printf_o(va_list, char *);
int my_printf_u(va_list, char *);
int my_printf_x(va_list, char *);
int my_printf_bx(va_list, char *);
int my_printf_b(va_list, char *);
int my_printf_p(va_list, char *);
int my_printf_br(va_list, char *);
int my_printf_n(va_list, char *);

#endif
