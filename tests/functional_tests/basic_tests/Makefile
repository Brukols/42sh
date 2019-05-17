##
## EPITECH PROJECT, 2018
## 42SH
## File description:
## A simple Makefile to compile functionnal tests
##

CC	=	gcc

all: my_divzero my_segfault

my_divzero:
	gcc -o my_divzero src/my_divzero.c

my_segfault:
	gcc -o my_segfault src/my_segfault.c

clean:
	$(RM) *.o

fclean:	clean
	$(RM) my_divzero
	$(RM) my_segfault
	$(RM) 42sh

re:	fclean all

.PHONY: all clean fclean re my_divzero my_segfault
