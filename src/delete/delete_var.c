/*
** EPITECH PROJECT, 2019
** 42SH
** File description:
** delete_varaible
*/

#include "shell.h"

void delete_var(t_variable *var)
{
    t_variable *tmp;

    if (!var)
        return;
    while (var) {
        tmp = var;
        free(var->name);
        free_array(var->arg);
        var = var->next;
        free(tmp);
    }
}
