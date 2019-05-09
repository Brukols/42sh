/*
** EPITECH PROJECT, 2018
** lib
** File description:
** my_itoa
*/

#include "my.h"

char *my_itoa(int number)
{
    int len = 0;
    int tmp = number;
    char *str = NULL;
    while (tmp != 0 || len == 0) {
        tmp = tmp / 10;
        len++;
    }
    if (number < 0) {
        number = number * -1;
        len++;
        tmp = -2;
    }
    str = my_calloc(len + 1, sizeof(char));
    while (len-- > 0) {
        str[len] = number % 10 + '0';
        number = number / 10;
    }
    if (tmp == -2)
        str[0] = '-';
    return (str);
}
