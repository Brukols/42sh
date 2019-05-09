/*
** EPITECH PROJECT, 2019
** 42SH
** File description:
** is_builtin
*/

#include "shell.h"

int is_builtin(char *name, t_builtin **builtin)
{
    int i = 0;
    while (builtin[i] != NULL) {
        if (my_strcmp(name, builtin[i]->name) == 0
        && my_strlen(name) == my_strlen(builtin[i]->name)) {
            return (i);
        }
        i++;
    }
    return (-1);
}
