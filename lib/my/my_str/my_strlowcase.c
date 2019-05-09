/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** my_strlowcase
*/

#include "my.h"

char *my_strlowcase(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if ('A' <= str[i] && str[i] <= 'Z')
            str[i] = str[i] + 32;
    }
    return str;
}
