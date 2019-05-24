/*
** EPITECH PROJECT, 2019
** 42SH
** File description:
** no_inhibitos
*/

#include "shell.h"

bool no_inhibitor(char *str, int i)
{
    if (i > 0 && str[i - 1] == '\\')
        return (true);
    return (false);
}