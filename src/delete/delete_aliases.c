/*
** EPITECH PROJECT, 2019
** 42SH
** File description:
** delete_aliases
*/

#include "shell.h"

void delete_aliases(aliase_t *aliases)
{
    aliase_t *tmp;

    if (!aliases)
        return;
    for (; aliases->prev; aliases = aliases->prev);
    while (aliases) {
        tmp = aliases;
        if (aliases->new_name)
            free(aliases->new_name);
        if (aliases->command)
            free(aliases->command);
        aliases = aliases->next;
        free(tmp);
    }
}
