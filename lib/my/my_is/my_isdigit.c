/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** my_isdigit
*/

#include "my.h"

int my_isdigit(char c)
{
    if ('0' <= c && c <= '9')
        return 1;
    return 0;
}
