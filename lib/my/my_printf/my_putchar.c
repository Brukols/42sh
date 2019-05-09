/*
** EPITECH PROJECT, 2018
** libmy - my_printf
** File description:
** my_putchar
*/

#include "my.h"

int my_putchar(int c)
{
    char t = (char)c;
    write(1, &t, 1);
    return 0;
}
