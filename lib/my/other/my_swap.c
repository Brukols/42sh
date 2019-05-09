/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** my_swap
*/

#include "my.h"

void my_swap(int *a, int *b)
{
    int c = *a;
    *a = *b;
    *b = c;
}
