##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Compile lib
##

CC=		gcc
CP=		cp -r
AR=		ar cr
FLAGS=	-Wall -Wextra -I./include

NAME=	libmy_getopt.a

INCLUDE_DIR=	$(realpath ./include)
INCLUDE=		$(INCLUDE_DIR)/my_getopt.h

SRC_DIR=	$(realpath ./src)
SRC=		$(SRC_DIR)/my_getopt.c                              \
			$(SRC_DIR)/scan.c                                   \
			$(SRC_DIR)/flag.c                                   \
			$(SRC_DIR)/error.c

OBJ=		$(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ) $(INCLUDE)
	$(AR) $(NAME) $(OBJ)
	$(CP) $(NAME) ../
	$(CP) $(INCLUDE) ../../include

.c.o:
	$(CC) $(FLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJ)

fclean:		clean
	rm -rf $(NAME)
	rm -rf ../$(NAME)

re: fclean all

.PHONY: clean fclean re all
