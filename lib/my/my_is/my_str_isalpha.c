/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** my_str_isalpha
*/

#include "my.h"

int my_str_isalpha(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (!(('A' <= str[i] && str[i] <= 'Z')
            || ('a' <= str[i] && str[i] <= 'z')))
            return 0;
    }
    return 1;
}
