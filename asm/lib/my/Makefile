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

NAME=	libmy.a

INCLUDE_DIR=	$(realpath ./include)
INCLUDE=		$(INCLUDE_DIR)/my.h                            \
				$(INCLUDE_DIR)/my_printf.h                     \
				$(INCLUDE_DIR)/get_next_line.h

SRC_DIR=	$(realpath ./src)
SRC=		$(SRC_DIR)/integers/number_len.c                   \
			$(SRC_DIR)/integers/get_digit.c                    \
			$(SRC_DIR)/integers/my_swap.c                      \
			$(SRC_DIR)/integers/is_digit.c                     \
			$(SRC_DIR)/integers/my_atoi.c                      \
			$(SRC_DIR)/nbr/my_getnbr.c                         \
			$(SRC_DIR)/nbr/my_put_nbr.c                        \
			$(SRC_DIR)/nbr/my_putnbr_base.c                    \
			$(SRC_DIR)/str/my_putstr.c                         \
			$(SRC_DIR)/str/my_revstr.c                         \
			$(SRC_DIR)/str/my_showstr.c                        \
			$(SRC_DIR)/str/my_strcapitalize.c                  \
			$(SRC_DIR)/str/my_strcat.c                         \
			$(SRC_DIR)/str/my_strcmp.c                         \
			$(SRC_DIR)/str/my_strcpy.c                         \
			$(SRC_DIR)/str/my_strdup.c                         \
			$(SRC_DIR)/str/my_strndup.c                        \
			$(SRC_DIR)/str/my_strlen.c                         \
			$(SRC_DIR)/str/my_strncat.c                        \
			$(SRC_DIR)/str/my_strncmp.c                        \
			$(SRC_DIR)/str/my_strncpy.c                        \
			$(SRC_DIR)/str/my_strstr.c                         \
			$(SRC_DIR)/char/is_char.c                          \
			$(SRC_DIR)/char/my_putchar.c                       \
			$(SRC_DIR)/char/get_next_line.c                    \
			$(SRC_DIR)/char/itoa.c                             \
			$(SRC_DIR)/my_printf/my_printf.c                   \
			$(SRC_DIR)/my_printf/my_printf_flag.c              \
			$(SRC_DIR)/my_printf/my_printf_usigned.c           \
			$(SRC_DIR)/my_printf/my_printf_padding.c           \
			$(SRC_DIR)/my_printf/my_printf_color.c             \
			$(SRC_DIR)/my_printf/my_printf_pointers.c

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
