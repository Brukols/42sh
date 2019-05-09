/*
** EPITECH PROJECT, 2018
** myprinte.h
** File description:
** prototypes of my_printe
*/

#ifndef MYPRINTE_H
#define MYPRINTE_H

int my_printe(const char *str, ...);
int esort_flags(char flag, void *arg);
int emy_put_nbr_binary(long long nbr);
int emy_put_nbr_hexa(long long nbr);
int emy_put_nbr_hexa_capitalize(long long nbr);
int emy_put_nbr_octal(long long nbr);
int emy_put_ptr_add(long long add);
int emy_putstr_np(char *str);
void emy_put_np(char str);
int emy_put_nbr(int nbr);
int emy_putchar(int c);
int emy_putstr(char const *str);
void my_puterror(char *str);

typedef struct s_printe
{
    int (*ptr)();
    char flag;
} t_printe;

#endif
