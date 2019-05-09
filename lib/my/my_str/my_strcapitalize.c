/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** my_strcapitalize
*/

#include "my.h"

char *my_strcapitalize(char *str)
{
    int i = 0;
    while (str[i] != '\0') {
        if ('A' <= str[i] && str[i] <= 'Z')
            str[i] = str[i] + 32;
        i++;
    }
    i = 1;
    if ('a' <= str[0] && str[0] <= 'z')
        str[0] = str[0] - 32;

    while (str[i] != '\0') {
        if (str[i - 1] <= 47 && 'a' <= str[i] && str[i] <= 'z')
            str[i] = str[i] - 32;
        i++;
    }
    return str;
}
