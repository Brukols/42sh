/*
** EPITECH PROJECT, 2019
** 42SH
** File description:
** check_sep
*/

#include "shell.h"

int check_sep(char c, char *sep)
{
    for (int i = 0; sep[i]; i++) {
        if (c == sep[i] || c == '\0')
            return (1);
    }
    return (0);
}
