/*
** EPITECH PROJECT, 2018
** libmy - my_printe
** File description:
** emy_put_nbr_octal
*/

#include "my.h"

int emy_put_nbr_octal(long long nbr)
{
    int digits = 0;
    if (nbr < 9) {
        emy_putchar(nbr + 48);
    }
    else if (nbr > 8) {
        emy_put_nbr_octal(nbr/8);
        digits = nbr % 8;
        emy_putchar(digits + 48);
    }
    return 0;
}
