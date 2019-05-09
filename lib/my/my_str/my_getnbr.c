/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** my_getnbr
*/

#include "my.h"

int my_getnbr(char const *str)
{
    int number = 0;
    int neg = 1;
    int i = 0;

    for (i = 0; str[i] == '-' || str[i] == '+'; i++) {
        if (str[i] == '-')
            neg = neg * -1;
    }
    for (int j = i; '0' <= str[j] && str[j] <= '9'; j++) {
        number = number * 10;
        number = number + str[j] - 48;
    }
    return (number * neg);
}
