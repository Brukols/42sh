/*
** EPITECH PROJECT, 2018
** libmy - my_printe
** File description:
** emy_put_ptr_add
*/

#include "my.h"

int emy_put_ptr_add(long long add)
{
    if (add == 0) {
        emy_putstr("(nil)");
        return 0;
    }

    emy_putstr("0x");
    emy_put_nbr_hexa(add);
    return 0;
}
