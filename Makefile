##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

.SUFFIXES: .c .o

all:
	make -C asm/
	make -C corewar/

clean:
	make -C asm/ clean
	make -C corewar/ clean

fclean:		clean
	make -C asm/ fclean
	make -C corewar/ fclean

re: clean fclean
	make -C asm/ re
	make -C corewar/ re

.PHONY: clean fclean re
