/*
** EPITECH PROJECT, 2017
** libmy.h
** File description:
** header for lib my
*/

#ifndef LIB_MY_H_
#define LIB_MY_H_

#include "my_printf.h"
#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>

#ifndef NULL
#define NULL 0
#endif

void my_putchar(char);
void my_swap(int *, int *);
int my_putnbr_base(int, char const *);
int my_put_nbr(int);
int my_showstr(char const *);
int number_len(int);
int my_putstr(char const *);
int get_digit(int, int);
int my_getnbr(char *);
int my_strcmp(char const *, char const *);
int my_strncmp(char const *, char const *, int);
int my_strlen(char const *);
int is_digit(char);
int is_char(char);
int my_atoi(const char *);
char *my_itoa(int);
char *my_revstr(char *);
char *my_strcat(char *, char const *);
char *my_strncat(char *, char const *, int);
char *my_strcpy(char *, char const *);
char *my_strncpy(char *, char const *, int);
char *my_strstr(char *, char const *);
char *my_strdup(char const *);
char *my_strndup(char const *, int);
char *my_strcapitalize(char *);

#endif
