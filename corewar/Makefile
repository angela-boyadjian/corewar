##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

SRC	=	srcs/main.c						\
		srcs/args_errors/error_gest_controler.c			\
		srcs/args_errors/ac_errors/number_of_ac_errors.c	\
		srcs/args_errors/av_errors/check_for_flags.c		\
		srcs/args_errors/av_errors/dot_cor_errors.c		\
		srcs/args_errors/av_errors/flags_errors.c		\
		srcs/args_errors/av_errors/look_ff_errors.c		\
		srcs/vm/init_champions.c				\
		srcs/op.c						\
		srcs/vm/recup_instruct/ldi.c				\
		srcs/vm/recup_instruct/sti.c				\
		srcs/vm/recup_instruct/instructions_ele_fif.c		\
		srcs/vm/recup_instruct/instructions_one_five.c		\
		srcs/vm/recup_instruct/instructions_sixteen.c		\
		srcs/vm/recup_instruct/instructions_six_ten.c		\
		srcs/vm/recup_instruct/read_headers.c			\
		srcs/vm/recup_instruct/read_instructions.c		\
		srcs/vm/recup_instruct/read_parameters.c		\
		srcs/vm/recup_instruct/switch_endian.c			\
		srcs/vm/recup_instruct/init_data_base.c			\
		srcs/vm/init_vm.c					\
		srcs/vm/save_id.c					\
		srcs/vm/recup_args/clist_argv.c				\
		srcs/vm/clist_arg_champ.c				\
		srcs/vm/put_instru_in_memory.c				\
		srcs/vm/pu_in_me_two.c				\
		srcs/vm/instructions/get_nbr_from_size.c		\
		srcs/vm/instructions/one_to_five.c			\
		srcs/vm/instructions/six_to_ten.c			\
		srcs/vm/instructions/eleven_to_fifteen.c		\
		srcs/vm/instructions/sixteen.c				\
		srcs/vm/champions/param_error.c				\
		srcs/fight/champ_instruction.c				\
		srcs/vm/champions/pars_champ.c				\
		srcs/fight/exec_instructions.c				\
		srcs/fight/fight_loop.c					\
		srcs/fight/check_live.c					\

OBJ	=	$(SRC:.c = .o)

NAME	=	corewar

LIB_DIR	=	./lib

MY.H_DIR	=	./include

CC	=	gcc -g3

C_FLAGS	=	-Wall -Wextra

LIB_FLAG	=	-L$(LIB_DIR) -lmy

INCL_FLAG	=	-I$(MY.H_DIR)

all:	$(NAME)

$(NAME):	$(OBJ)
		$(MAKE) -C lib/my
		$(CC) -o $(NAME) $(OBJ) $(C_FLAGS) $(LIB_FLAG) $(INCL_FLAG)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: fclean all re clean
