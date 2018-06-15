/*
** EPITECH PROJECT, 2017
** my_getopt.h
** File description:
** <..>
*/

#ifndef MY_GETOPT_H_
#define MY_GETOPT_H_

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

struct optarg {
	char	*opt;
	int	no;
	struct optarg *next;
};

int my_getopt(int argc, char *argv[], const char *optstring);
int in_optstring(const char *optstring, char c);
char *get_flag(char *str, int *x, const char *optstring);
int has_arg(const char *optstring, char c);
int in_arg(char const *argv);
int len(char const *str);
char *dup_str(char const *src);
void my_puts(char *str);
int move_arr(char *av[], int pos);

char *my_optarg;
int my_optopt;
int my_optind;
struct optarg *crnt;

#endif
