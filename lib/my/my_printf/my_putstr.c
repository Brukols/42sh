/*
** EPITECH PROJECT, 2018
** libmy - my_printf
** File description:
** my_putstr
*/

#include "my.h"

int my_putstr(char const *str)
{
    write(1, str, my_strlen(str));
    return 0;
}
