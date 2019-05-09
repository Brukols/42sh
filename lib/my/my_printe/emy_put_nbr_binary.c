/*
** EPITECH PROJECT, 2018
** libmy - my_printe
** File description:
** emy_put_nbr_binary
*/

#include "my.h"

int emy_put_nbr_binary(long long nbr)
{
    int digits = 0;
    if (nbr < 2) {
        emy_putchar(nbr + 48);
    }
    else if (nbr > 1) {
        emy_put_nbr_binary(nbr / 2);
        digits = nbr % 2;
        emy_putchar(digits + 48);
    }
    return 0;
}
