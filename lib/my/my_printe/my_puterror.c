/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** my_puterror
*/

#include "my.h"

void my_puterror(char *str)
{
    write(2, str, my_strlen(str));
}
