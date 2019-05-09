/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** my_str_isprintable
*/

#include "my.h"

int my_str_isprintable(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] <= 31) {
            return 0;
        }
    }
    return 1;
}
