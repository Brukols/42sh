/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** my_str_islower
*/

#include "my.h"

int my_str_islower(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (!('a' <= str[i] && str[i] <= 'z'))
            return 0;
    }
    return 1;
}
