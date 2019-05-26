/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** alias
*/

#include "shell.h"

bool ignore_same_alias(aliase_t *aliase, char *new_name)
{
    aliase_t *alias = aliase;

    for (; alias->prev != NULL; alias = alias->prev);
    for (; alias != NULL; alias = alias->next)
        if (my_strcmp(alias->new_name, new_name) == 0)
            return true;
    return false;
}

aliase_t *add_alias_in_list(char *new_name, char *command, aliase_t *alias)
{
    if (ignore_same_alias(alias, new_name) == true)
        return alias;
    for (; alias->next != NULL; alias = alias->next);
    if ((alias->next = malloc(sizeof(aliase_t))) == NULL)
        return NULL;
    if ((alias->next->new_name = my_strdup(new_name)) == NULL)
        return NULL;
    if ((alias->next->command = my_strdup(command)) == NULL)
        return NULL;
    alias->next->next = NULL;
    alias->next->prev = alias;
    return alias;
}
