/*
** EPITECH PROJECT, 2018
** libmy - my_printf
** File description:
** my_put_ptr_add
*/

#include "my.h"

int my_put_ptr_add(long long add)
{
    if (add == 0) {
        my_putstr("(nil)");
        return 0;
    }

    my_putstr("0x");
    my_put_nbr_hexa(add);
    return 0;
}
