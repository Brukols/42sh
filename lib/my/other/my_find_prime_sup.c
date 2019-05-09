/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** my_find_prime_sup
*/

#include "my.h"

int my_find_prime_sup(int nb)
{
    while (my_is_prime(nb) != 1) {
        nb++;
    }
    return nb;
}
