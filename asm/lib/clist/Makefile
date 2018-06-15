##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Compile lib
##

CC=		gcc
CP=		cp -r
AR=		ar cr
FLAGS=	-g3 -Wall -Wextra -Werror -I./include

NAME=	libclist.a

INCLUDE_DIR=	$(realpath ./include)
INCLUDE=		$(INCLUDE_DIR)/clist.h

SRC_DIR=	$(realpath ./src)
SRC=		$(SRC_DIR)/util/dupstr.c                                     \
			$(SRC_DIR)/util/len.c                                        \
			$(SRC_DIR)/util/stoi.c                                       \
			$(SRC_DIR)/util/stristr.c                                    \
			$(SRC_DIR)/stack/add_stack.c                                 \
			$(SRC_DIR)/stack/pop_stack.c                                 \
			$(SRC_DIR)/queue/add_queue.c                                 \
			$(SRC_DIR)/queue/pop_queue.c                                 \
			$(SRC_DIR)/d_queue/add_d_queue.c                             \
			$(SRC_DIR)/d_queue/pop_d_queue.c                             \
			$(SRC_DIR)/tree/add_tree.c                                   \
			$(SRC_DIR)/tree/pop_tree.c

OBJ=		$(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ) $(INCLUDE)
	$(AR) $(NAME) $(OBJ)
	$(CP) $(NAME) ../
	$(CP) $(INCLUDE) ../../include/

.c.o:
	$(CC) $(FLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJ)

fclean:		clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean re
