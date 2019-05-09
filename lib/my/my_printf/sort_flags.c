/*
** EPITECH PROJECT, 2018
** libmy - my_printf
** File description:
** sort_flags
*/

#include "my.h"

int sort_flags(char flag, void *arg)
{
    t_printf func_tab[] =
    {
        {&my_put_nbr, 'i'},
        {&my_put_nbr, 'd'},
        {&my_putchar, 'c'},
        {&my_putstr, 's'},
        {&my_put_ptr_add, 'p'},
        {&my_put_nbr_hexa, 'x'},
        {&my_put_nbr_hexa_capitalize, 'X'},
        {&my_put_nbr_octal, 'o'},
        {&my_put_nbr_binary, 'b'},
        {&my_putstr_np, 'S'},
        {&my_put_nbr, 'u'},
        {NULL, 0}
    };
    for (int i = 0; func_tab[i].flag != 0; i++) {
        if (func_tab[i].flag == flag)
            func_tab[i].ptr(arg);
    }
    return 0;
}
