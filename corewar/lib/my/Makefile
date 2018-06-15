##
## EPITECH PROJECT, 2017
## Makefile
## File description:
##
##

SRC	=	$(wildcard *.c)		\
		my_printf/my_printf.c	\
		my_printf/cases.c	\
		my_printf/cases2.c	\
		my_printf/cases3.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

AR	=	ar rc

all:	$(NAME) clean

$(NAME):	$(OBJ)
		$(AR) ../$(NAME) $(OBJ)
		rm *.o
		rm my_printf/*.o
clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
