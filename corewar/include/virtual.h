/*
** EPITECH PROJECT, 2017
** virtual.h
** File description:
** Arthur
*/

#include "struct.h"
#include "instructions.h"
#include "my.h"
#include "op.h"

#ifndef VIRTUAL_H_
#define VIRTUAL_H_

enum active {
	OFF = 0,
	ON = 1
};

enum flag {
	D = 0,
	A = 1,
	N = 2
};

int ar_er(int ac, char **av);
int check_one_ac(int ac, char **av);

int fct_open(char *av);
int looking_for_flag(char **av, int i);
int hexa_gest(char *av, char *dmp);
int g_flag(char *av);
int check_dump(char *av);
int check_cor(char **av, int i);
int check_fl_n(char *flag, char *av);
int check_fl_a(char *av, char *params);
void put_compil_error(void);
int send_to_flag_handler(int (*flag_handler[3])(char *flag, char *argv),
char **av, int i);
int lf_flag_err(int (*flag_handler[3])(char *flag, char *argv),
char **av, int i);
void reset_cor(char *av, int *hyp_a, int *hyp_n);
int double_arg(int dump, int hyp_a, int hyp_n);

arg_champ *put_arg(int ac, char **av);
arg_champ *init_ag_champ(int hyp_a, int hyp_n, char *av);
int insert_begin(arg_champ **first_elem, int hyp_a, int hyp_n, char *av);
int insert_end(arg_champ **first_elem, int hyp_a, int hyp_n, char *av);
void insert_nbr_champ(arg_champ **first_elem, int nbr);
void memory_memset(char *memory, int size);
int adr_acc(int adr);
int set_flag(int adr);

int init_champions(champions **champ, arg_champ *av_list);
int memset_champion_registers(champions *champ);

int init_data_base(instructions **list, arg_champ *av_list);

void switch_endian_two(union endian *value);
void switch_endian_four(union endian *value);

int read_headers(instructions *list, int fd);
int check_name_comment(char *name, char *comment);
int headers_error_handling(struct header_s *files_h);

int save_id(char **champ_name, champions **champ);
int memory_init(circular_memory *vm, champions **champ, arg_champ *av_list,
int size);
void memory_put_move(circular_memory *vm, champions *champ, char data, int adr);
int put_instructions_in_memory(champions **champ, circular_memory *vm);
void dec_to_hexa(char *tmp, int value);
void cpy_dec(char *tmp, int *i, char *nb);
void instruction_str(char *tmp, instructions *list);
instructions *put_one_champ_in_memory(champions *champ, circular_memory *vm);

instructions *read_instructions(int fd, instructions *list);
int read_live(instructions *list, int fd);
int read_ld(instructions *list, int fd);
int read_st(instructions *list, int fd);
int read_add(instructions *list, int fd);
int read_sub(instructions *list, int fd);
int read_and(instructions *list, int fd);
int read_or(instructions *list, int fd);
int read_xor(instructions *list, int fd);
int read_zjmp(instructions *list, int fd);
int read_ldi_instruction(instructions *list, int fd);
int read_sti_instruction(instructions *list, int fd);
int read_fork(instructions *list, int fd);
int read_lld(instructions *list, int fd);
int read_lldi(instructions *list, int fd);
int read_lfork(instructions *list, int fd);
int read_aff(instructions *list, int fd);

int read_in_struct(instructions *list, int val, int j, int fd);
struct parameters recup_parameters(int types);
int read_value_of_param(int *types, int value, int fd);
int read_parameters(instructions *list, int code, int nb_arg, int fd);
int	do_malloc(circular_memory *vm, champions **champ, int size);

int read_for_ldi(instructions *list, int val, int i, int fd);
int read_ldi(instructions *list, int code, int nb_arg, int fd);
int read_for_sti(instructions *list, int val, int i, int fd);
int read_sti(instructions *list, int code, int nb_arg, int fd);

int recup_instruction(instructions *instr, circular_memory *vm,
champions *champ);
int cycles(circular_memory *vm, champions **champ);

int is_good_params(int types, int inst);
int rec_instru(champions *champ);
int rec_adr(champions *champ);

int getnbr_from_size(champions *champ, int size);

int inst_cycle(int inst);
int is_adr(int ins);
int exec_instruc(champions *champ, circular_memory *vm,
int (*exec_tab[16])(circular_memory *vm, champions *champ));

int champ_loop(champions **champ, circular_memory *vm,
int (*exec_tab[16])(circular_memory *vm, champions *champ));

int champ_instru(champions *champ);
int champ_params_types(champions *champ, int nb_params);
int nb_params_ins(int ins);

void init_exec_instru_tab(int (*exec_instru_tab[16])(circular_memory *vm,
champions *champ));

int fight_loop(circular_memory *vm, champions **champ);
int check_live(circular_memory *vm, champions **champ);

void print_memory(char *memory);
void init_lives(int *nb, int size);
void cpy_mne_adr(char *tmp, int *i, instructions *list);

#endif