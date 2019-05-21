##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## A simple Makefile to compile my project with my lib
##

NAME	=	libmy.a

SRC	=	array/free_array.c	\
		array/get_size_array.c	\
		array/my_array_cpy.c	\
		array/my_show_word_array.c	\
		array/my_sort_int_array.c	\
		array/print_array.c	\
		array/create_array.c	\
		array/my_arraylen.c	\
		array/my_arraydup.c	\
		array/my_arraydup.c	\
		array/my_realloc_array.c	\
		getnextline/get_next_line.c	\
		my_is/my_is_prime.c	\
		my_is/my_isdigit.c	\
		my_is/my_isneg.c	\
		my_is/my_str_is_num.c	\
		my_is/my_str_isalpha.c	\
		my_is/my_str_islower.c	\
		my_is/my_str_isprintable.c	\
		my_is/my_str_isupper.c	\
		my_mem/my_calloc.c	\
		my_mem/my_memset.c	\
		my_printe/my_printe.c	\
		my_printe/emy_put_nbr_binary.c	\
		my_printe/emy_put_nbr_hexa_capitalize.c	\
		my_printe/emy_put_nbr_hexa.c	\
		my_printe/emy_put_nbr_octal.c	\
		my_printe/emy_put_nbr.c	\
		my_printe/emy_put_ptr_add.c	\
		my_printe/emy_putchar.c	\
		my_printe/emy_putstr_np.c	\
		my_printe/emy_putstr.c	\
		my_printe/esort_flags.c	\
		my_printe/my_puterror.c	\
		my_printf/is_flag.c	\
		my_printf/my_printf.c	\
		my_printf/my_put_nbr_binary.c	\
		my_printf/my_put_nbr_hexa_capitalize.c	\
		my_printf/my_put_nbr_hexa.c	\
		my_printf/my_put_nbr_octal.c	\
		my_printf/my_put_nbr.c	\
		my_printf/my_put_ptr_add.c	\
		my_printf/my_putchar.c	\
		my_printf/my_putstr_np.c	\
		my_printf/my_putstr.c	\
		my_printf/sort_flags.c	\
		my_str/my_getnbr.c	\
		my_str/my_itoa.c	\
		my_str/my_revstr.c	\
		my_str/my_str_to_word_array.c	\
		my_str/my_strcapitalize.c	\
		my_str/my_strcat.c	\
		my_str/my_strcmp.c	\
		my_str/my_strcpy.c	\
		my_str/my_strdup.c	\
		my_str/my_strlen.c	\
		my_str/my_strlowcase.c	\
		my_str/my_strncat.c	\
		my_str/my_strncmp.c	\
		my_str/my_strncpy.c	\
		my_str/my_strstr.c	\
		my_str/my_strupcase.c	\
		other/my_compute_power_rec.c	\
		other/my_compute_square_root.c	\
		other/my_find_prime_sup.c	\
		other/my_swap.c	\

CFLAGS = 	-I../include -W -Wall -Wshadow -Wextra -Werror

OBJ	=	$(SRC:.c=.o)

CC	=	gcc

all:	$(OBJ)
	ar rc $(NAME) $(OBJ)
	mv $(NAME) ./../

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf ./../$(NAME)

re: fclean all

.PHONY: all clean fclean re
