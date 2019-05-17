##
## EPITECH PROJECT, 2018
## 42SH
## File description:
## A simple Makefile to compile functionnal tests
##

CC	=	gcc

compile_src: my_divzero my_segfault
	cp ../../42sh .

my_divzero:
	gcc -w -o my_divzero src/my_divzero.c

my_segfault:
	gcc -o my_segfault src/my_segfault.c

run_test:
	./tester.sh

clean:
	$(RM) *.o

fclean:	clean
	$(RM) my_divzero
	$(RM) my_segfault
	$(RM) 42sh

re:	fclean all

.PHONY: all clean fclean re my_divzero my_segfault
