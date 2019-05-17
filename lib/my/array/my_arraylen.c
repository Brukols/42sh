/*
** EPITECH PROJECT, 2019
** my_arraylen
** File description:
** lib
*/

#include "my.h"

int my_arraylen(char **arr)
{
    int i = 0;

    for (; arr[i]; i++);
    return (i);
}
