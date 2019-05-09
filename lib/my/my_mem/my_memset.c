/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** my_memset
*/

#include "my.h"

char *my_memset(void *dest, char c, int size)
{
    int i = 0;
    char *d = dest;

    if (d != NULL) {
        while (i < size) {
            d[i] = c;
            i++;
        }
        return dest;
    }
    return NULL;
}
