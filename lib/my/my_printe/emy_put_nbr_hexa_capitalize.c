/*
** EPITECH PROJECT, 2018
** libmy - my_printe
** File description:
** emy_put_nbr_hexa_capitalize
*/

#include "my.h"

int emy_put_nbr_hexa_capitalize(long long nbr)
{
    int digits = 0;

    if (nbr < 0) {
        emy_putchar(45);
        nbr = -nbr;
    }
    if (nbr < 17) {
        if (nbr > 9)
            emy_putchar(nbr + 55);
        else
            emy_putchar(nbr + 48);
    } else if (nbr > 16) {
        emy_put_nbr_hexa_capitalize(nbr/16);
        digits = nbr % 16;
        if (digits > 9)
            emy_putchar(digits + 55);
        else
            emy_putchar(digits + 48);
    }
    return 0;
}
