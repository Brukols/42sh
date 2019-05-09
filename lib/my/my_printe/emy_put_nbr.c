/*
** EPITECH PROJECT, 2018
** libmy - my_printe
** File description:
** emy_put_nbr
*/

#include "my.h"

int emy_put_nbr(int nbr)
{
    int digits = 0;

    if (nbr == -2147483648)
        emy_putstr("-2147483648");
    else {

        if (nbr < 0) {
            emy_putchar(45);
            nbr = -nbr;
        }
        if (nbr < 10) {
            emy_putchar(nbr + 48);
        }
        else if (nbr > 9) {
            emy_put_nbr(nbr / 10);
            digits = nbr % 10;
            emy_putchar(digits + 48);
        }
    }
    return 0;
}
