/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** my_compute_square_root
*/

#include "my.h"

int my_compute_square_root(int nb)
{
    int i = 0;
    while (i * i != nb) {
        if (i < ((nb / 2) + 1)) {
            i++;
        } else {
            return 0;
        }
    }
    return i;
}
