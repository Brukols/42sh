/*
** EPITECH PROJECT, 2018
** libmy - my_printf
** File description:
** my_put_nbr_hexa
*/

#include "my.h"

int my_put_nbr_hexa(long long nbr)
{
    int digits = 0;

    if (nbr < 0) {
        my_putchar(45);
        nbr = -nbr;
    }
    if (nbr < 17) {
        if (nbr > 9)
            my_putchar(nbr + 87);
        else
            my_putchar(nbr + 48);
    } else if (nbr > 16) {
        my_put_nbr_hexa(nbr/16);
        digits = nbr % 16;
        if (digits > 9)
            my_putchar(digits + 87);
        else
            my_putchar(digits + 48);
    }
    return 0;
}
