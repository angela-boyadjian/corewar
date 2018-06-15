##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Compile lib
##

CC=		gcc
CP=		cp -r
AR=		ar cr
FLAGS=	-g3 -Wall -Wextra -I./include

NAME=	libmy_fgets.a

INCLUDE_DIR=	$(realpath ./include)
INCLUDE=		$(INCLUDE_DIR)/my_fgets.h

SRC_DIR=	$(realpath ./srcs)
SRC=		$(SRC_DIR)/my_fgets.c                              \
			$(SRC_DIR)/my_getchar.c                            \

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
