/*
** EPITECH PROJECT, 2018
** libmy - my_printe
** File description:
** emy_putchar
*/

#include "my.h"

int emy_putchar(int c)
{
    char t = (char)c;
    write(2, &t, 1);
    return 0;
}
