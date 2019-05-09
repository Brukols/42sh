/*
** EPITECH PROJECT, 2018
** libmy - my_printe
** File description:
** emy_putstr
*/

#include "my.h"

int emy_putstr(char const *str)
{
    write(2, str, my_strlen(str));
    return 0;
}
