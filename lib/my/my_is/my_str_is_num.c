/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** my_str_is_num
*/

#include "my.h"

int my_str_is_num(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (!(('0' <= str[i] && str[i] <= '9')
            || str[i] == '+' || str[i] == '-'))
            return 0;
    }
    return 1;
}
