/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** my_calloc
*/

#include "my.h"

void *my_calloc(int n, int size)
{
    void *ptr = malloc(size * n);

    if (ptr == NULL)
        return NULL;
    my_memset(ptr, 0, n);

    return ptr;
}
