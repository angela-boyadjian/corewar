/*
** EPITECH PROJECT, 2017
** printf.h
** File description:
** prots
*/

#ifndef PRINTF_H_
#define PRINTF_H_

int my_printf(char const *str, ...);
int case_s(va_list ap);
int case_d(va_list ap);
int case_c(va_list ap);
int case_u(va_list ap);
int case_x(va_list ap);
int case_o(va_list ap);
int case_p(va_list ap);
int case_b(va_list ap);
int case_smaj(va_list ap);
int case_mod(va_list ap);
int case_smaj(va_list ap);
int case_xmaj(va_list ap);
int my_error(char str);

#endif
