/*
** EPITECH PROJECT, 2019
** 42SH
** File description:
** delete_builtin
*/

#include "shell.h"

t_builtin **delete_builtin(t_builtin **builtin)
{
    if (!builtin)
        return (NULL);
    for (int i = 0; builtin != NULL && builtin[i] != NULL; i++) {
        free(builtin[i]->name);
        free(builtin[i]);
    }
    free(builtin);
    return (NULL);
}
