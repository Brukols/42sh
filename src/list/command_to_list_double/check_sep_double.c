/*
** EPITECH PROJECT, 2019
** 42SH
** File description:
** check_sep_double
*/

#include "shell.h"

int check_sep_double(char c, char d, char *sep)
{
    for (int i = 0; sep[i]; i += 2) {
        if ((c == sep[i] && d == sep[i + 1]) || c == '\0') {
            return (1);
        }
    }
    return (0);
}
