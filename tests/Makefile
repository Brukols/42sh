##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile for Unit Test of Infinadd Project
##

NAME	=	unit_tests

SRC	=	\

LIB_TEST	=	tests_libmy/tests_my_is/tests_my_is_prime.c	\
				tests_libmy/tests_my_is/tests_my_isdigit.c	\
				tests_libmy/tests_my_is/tests_my_isneg.c	\
				tests_libmy/tests_my_is/tests_my_str_is_num.c	\
				tests_libmy/tests_my_is/tests_my_str_isalpha.c	\
				tests_libmy/tests_my_is/tests_my_str_islower.c	\
				tests_libmy/tests_my_is/tests_my_str_isprintable.c	\
				tests_libmy/tests_my_is/tests_my_str_isupper.c	\
				tests_libmy/tests_my_printf/tests_is_flag.c	\
				tests_libmy/tests_my_printf/tests_my_printf.c	\
				tests_libmy/tests_my_printf/tests_my_put_nbr_binary.c	\
				tests_libmy/tests_my_printf/tests_my_put_nbr_hexac.c	\
				tests_libmy/tests_my_printf/tests_my_put_nbr_hexa.c	\
				tests_libmy/tests_my_printf/tests_my_put_nbr_octal.c	\
				tests_libmy/tests_my_printf/tests_my_put_nbr.c	\
				tests_libmy/tests_my_printf/tests_my_putchar.c	\
				tests_libmy/tests_my_printf/tests_my_putstr_np.c	\
				tests_libmy/tests_my_printf/tests_my_putstr.c	\
				tests_libmy/tests_my_printe/tests_emy_put_nbr_binary.c	\
				tests_libmy/tests_my_printe/tests_emy_put_nbr_hexac.c	\
				tests_libmy/tests_my_printe/tests_emy_put_nbr_hexa.c	\
				tests_libmy/tests_my_printe/tests_emy_put_nbr_octal.c	\
				tests_libmy/tests_my_printe/tests_emy_put_nbr.c	\
				tests_libmy/tests_my_printe/tests_emy_putchar.c	\
				tests_libmy/tests_my_printe/tests_emy_putstr_np.c	\
				tests_libmy/tests_my_printe/tests_emy_putstr.c	\
				tests_libmy/tests_my_printe/tests_my_printe.c	\
				tests_libmy/tests_my_str/tests_my_getnbr.c	\
				tests_libmy/tests_my_str/tests_my_itoa.c	\
				tests_libmy/tests_my_str/tests_my_revstr.c	\
				tests_libmy/tests_my_str/tests_my_strcapitalize.c	\
				tests_libmy/tests_my_str/tests_my_strcat.c	\
				tests_libmy/tests_my_str/tests_my_strcmp.c	\
				tests_libmy/tests_my_str/tests_my_strcpy.c	\
				tests_libmy/tests_my_str/tests_my_strdup.c	\
				tests_libmy/tests_my_str/tests_my_strlen.c	\
				tests_libmy/tests_my_str/tests_my_strlowcase.c	\
				tests_libmy/tests_my_str/tests_my_strncat.c	\
				tests_libmy/tests_my_str/tests_my_strupcase.c	\
				tests_libmy/tests_my_str/tests_my_strncmp.c	\
				tests_libmy/tests_my_str/tests_my_strncpy.c	\
				tests_libmy/tests_my_str/tests_my_strstr.c	\
				tests_libmy/tests_my_str/tests_my_str_to_word_array.c	\
				tests_libmy/tests_my_mem/tests_my_memset.c	\
				tests_libmy/tests_my_mem/tests_my_calloc.c	\
				tests_libmy/tests_other/tests_my_compute_power_rec.c	\
				tests_libmy/tests_other/tests_my_compute_square_root.c	\
				tests_libmy/tests_other/tests_my_find_prime_sup.c	\
				tests_libmy/tests_other/tests_my_swap.c	\
				tests_libmy/tests_array/tests_get_size_array.c	\
				tests_libmy/tests_array/tests_free_array.c	\
				tests_libmy/tests_array/tests_my_array_cpy.c	\
				tests_libmy/tests_array/tests_my_show_word_array.c	\
				tests_libmy/tests_array/tests_my_sort_int_array.c	\
				tests_libmy/tests_array/tests_print_array.c	\

SRC_TEST	=	tests_redirect.c	\

OBJECTS	=	$(SRC:.c=.o) $(SRC_TEST:.c=.o) $(LIB_TEST:.c=.o)

CFLAGS	=	-W -Wall -Wshadow -Wextra -Werror -I../lib/include -I../include --coverage

LDFLAGS	=	-L./../lib/ --coverage -lmy -lcriterion

CC	=	gcc

all: $(OBJECTS)
	$(CC) -o $(NAME) $(OBJECTS) $(LDFLAGS)
	$(MAKE) --no-print-directory -s -C functional_tests/
	@echo -e "************  UNIT TEST LIB VERSION ************\n"
	./$(NAME)
	@echo -e "\n************  UNIT TEST 42SH VERSION ************\n"
	sleep 2
	$(MAKE) --no-print-directory -s -C functional_tests/ run_test
	$(MAKE) --no-print-directory -s fclean
	@echo -e "\n************  END TEST ************"

clean:
	$(MAKE) --no-print-directory -s -C functional_tests/ clean
	rm -rf $(OBJECTS)
	rm -rf *.gcda
	rm -rf *.gcno

fclean:	clean
	$(MAKE) --no-print-directory -s -C functional_tests/ fclean
	rm -rf $(NAME)

re:	fclean	all

.PHONY: all clean fclean re
