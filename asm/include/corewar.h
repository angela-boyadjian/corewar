/*
** EPITECH PROJECT, 2017
** corewar.h
** File description:
** corewar header file
*/

#ifndef COREWAR_H_
#define COREWAR_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdbool.h>

#include "my.h"
#include "my_getopt.h"
#include "my_fgets.h"
#include "clist.h"
#include "op.h"
#include "define.h"

#define INSTRUCT_SIZE 1

enum type_e {
	L,
	I
};

enum token_e {
	REG,
	DRT,
	IND,
	LAB
};

struct	args_s {
	char	*args;
	enum	token_e tk_name;
};

union	endian {
	char	byte[4];
	int		val;
};

struct token
{
	enum type_e	tk_val;
	char		*mnemo;
	struct args_s	*arg_tab;
	int		arg_no;
	int		line;
	int		l_size;
	char		*fname;
};

//Lexer
int		get_cmd(char *cmd);
struct d_queue	*lex_file(char *);
int		is_line_comment(char *);
struct d_queue *lex_file(char *);
header_t	*create_header(int, char *, char *, int);
header_t *catch_header_error(header_t *, char *, int);
enum token_e	get_arg_type(char *);
int		is_line_comment(char *);
int		is_header(char *);
int		is_label(char *);
int		is_arg(char *);
int		is_mnemonic(char *);
int		count_arg(char *);
int		set_mem(struct token *, int);
int		skip_tabs(char *);
int		next_quote(char *, int);
int		skip_space_tabs(char *);
int		skip_space_tabs_arg(char *);
int		skip_space_tabs_lab(char *);
void		disp(struct token *);
int		is_noise(char *line);
void		catch_name(char *, header_t *, char *, int *);
void		catch_comment(char *, header_t *, char *, int *);

//Parser
void		add_cmd(struct token *, int);
void		add_adressage(struct token *, int);
int		my_compute_power_rec(int, int);
int		my_getnbr_base(char const *, char const *);
void		print_bits(struct token *, int, int);
void		parser(struct d_queue *, int);
void		registers(struct token *, int, int);
void		directs(struct token *, int , int);
void		indirects(struct token *, int, int);
void		swap_endian(union endian *);
void		add_header(struct d_queue *, int);
void		labels(struct d_queue *head, int fd, int i, struct token *);
bool		check_case(char *str);
void		add_param(struct d_queue *head, int fd, struct token *token);


// Error handling
int		error_handling(struct token *);
void		malloc_error(void);
void		*file_error(char *);
void		*file_error(char *);
void		error_invalid_instruct(char *, int);
void		malloc_error(void);
void		error_comment(char *, int);
void		error_name(char *, int);
void		syntax_error(char *, int);
void		my_memset(void *, int, unsigned int);
void		comment_after_name_error(char *, int);
void		name_on_first_line(char *, int);

#endif
