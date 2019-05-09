/*
** EPITECH PROJECT, 2018
** libmy - my_printe
** File description:
** emy_putstr_np
*/

#include "my.h"

void emy_put_np(char str)
{
    int c = str;
    int array[3] = {0};

    for (int i = 0; c > 0; i++) {
        array[i] = c % 8;
        c = c / 8;
    }
    emy_putchar('\\');
    for (int i = 2; i > -1; i--) {
        emy_put_nbr(array[i]);
    }
}

int emy_putstr_np(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] < 32 || str[i] >= 127)
            emy_put_np(str[i]);
        else
            emy_putchar(str[i]);
        i++;
    }
    return 0;
}
