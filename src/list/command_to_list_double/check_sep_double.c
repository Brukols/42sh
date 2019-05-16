/*
** EPITECH PROJECT, 2019
** 42SH
** File description:
** check_sep_double
*/

#include "shell.h"

int check_sep_double(char *c, int pos, char *sep)
{
    if (c[pos] == '\0')
        return (1);
    for (int i = 0; sep[i]; i += 2) {
        if ((c[pos] == sep[i] && c[pos + 1] == sep[i + 1])) {
            return (1);
        }
    }
    return (0);
}
