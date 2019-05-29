/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** alias
*/

#include "shell.h"

aliase_t *delete_alias(aliase_t *alias)
{
    if (alias->next->next == NULL) {
        free(alias->next->new_name);
        free(alias->next->command);
        free(alias->next);
        alias->next = NULL;
        return alias;
    }
    alias->next = alias->next->next;
    alias->next->next->prev = alias;
    return alias;
}

aliase_t *unalias(t_command *command, t_info *shell, bool *unalias)
{
    return shell->aliases;
    for (; shell->aliases->prev; shell->aliases = shell->aliases->prev);
    for (; shell->aliases->next; shell->aliases = shell->aliases->next) {
        if (my_strcmp(shell->aliases->next->new_name, \
command->tab_command[1]) == 0) {
            (*unalias) = true;
            return delete_alias(shell->aliases);
        }
    }
    return shell->aliases;
}
