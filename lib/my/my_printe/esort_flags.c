/*
** EPITECH PROJECT, 2018
** libmy - my_printe
** File description:
** esort_flags
*/

#include "my.h"

int esort_flags(char flag, void *arg)
{
    t_printe func_tab[] =
    {
        {&emy_put_nbr, 'i'},
        {&emy_put_nbr, 'd'},
        {&emy_putchar, 'c'},
        {&emy_putstr, 's'},
        {&emy_put_ptr_add, 'p'},
        {&emy_put_nbr_hexa, 'x'},
        {&emy_put_nbr_hexa_capitalize, 'X'},
        {&emy_put_nbr_octal, 'o'},
        {&emy_put_nbr_binary, 'b'},
        {&emy_putstr_np, 'S'},
        {&emy_put_nbr, 'u'},
        {NULL, 0}
    };
    for (int i = 0; func_tab[i].flag != 0; i++) {
        if (func_tab[i].flag == flag)
            func_tab[i].ptr(arg);
    }
    return 0;
}
