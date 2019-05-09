/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** my_strupcase
*/

#include "my.h"

char *my_strupcase(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if ('a' <= str[i] && str[i] <= 'z')
            str[i] = str[i] - 32;
    }
    return str;
}
