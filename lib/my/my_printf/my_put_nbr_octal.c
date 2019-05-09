/*
** EPITECH PROJECT, 2018
** libmy - my_printf
** File description:
** my_put_nbr_octal
*/

#include "my.h"

int my_put_nbr_octal(long long nbr)
{
    int digits = 0;
    if (nbr < 9) {
        my_putchar(nbr + 48);
    }
    else if (nbr > 8) {
        my_put_nbr_octal(nbr/8);
        digits = nbr % 8;
        my_putchar(digits + 48);
    }
    return 0;
}
