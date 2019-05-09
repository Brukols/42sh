/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** my_strlen
*/

#include "my.h"

int my_strlen(char const *str)
{
    if (str == NULL)
        return 0;
    int i = 0;
    while (str[i] != '\0') {
        i++;
    }
    return i;
}
