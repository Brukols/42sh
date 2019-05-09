/*
** EPITECH PROJECT, 2018
** myprintf.h
** File description:
** prototypes of my_printf
*/

#ifndef MYPRINTF_H
#define MYPRINTF_H

int my_printf(const char *str, ...);
int sort_flags(char flag, void *arg);
int is_flag(char f);
int my_put_nbr_binary(long long nbr);
int my_put_nbr_hexa(long long nbr);
int my_put_nbr_hexa_capitalize(long long nbr);
int my_put_nbr_octal(long long nbr);
int my_put_ptr_add(long long add);
int my_putstr_np(char *str);
void my_put_np(char str);
int my_put_nbr(int nbr);
int my_putchar(int c);
int my_putstr(char const *str);

typedef struct s_printf
{
    int (*ptr)();
    char flag;
} t_printf;

#endif
