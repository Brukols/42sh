/*
** EPITECH PROJECT, 2018
** libmy - my_printf
** File description:
** my_put_nbr
*/

#include "my.h"

int my_put_nbr(int nbr)
{
    int digits = 0;

    if (nbr == -2147483648)
        my_putstr("-2147483648");
    else {

        if (nbr < 0) {
            my_putchar(45);
            nbr = -nbr;
        }
        if (nbr < 10) {
            my_putchar(nbr + 48);
        }
        else if (nbr > 9) {
            my_put_nbr(nbr / 10);
            digits = nbr % 10;
            my_putchar(digits + 48);
        }
    }
    return 0;
}
