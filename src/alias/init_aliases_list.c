/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** aliases
*/

#include "shell.h"

aliase_t *add_alias_in_list(char *new_name, char *command, aliase_t *alias)
{
    for (; alias->next != NULL; alias = alias->next);
    if ((alias->next = malloc(sizeof(aliase_t))) == NULL)
        return NULL;
    if ((alias->next->new_name = my_strdup(new_name)) == NULL)
        return NULL;
    if ((alias->next->command = my_strdup(command)) == NULL)
        return NULL;
    alias->next->next = NULL;
    for (; alias->prev != NULL; alias = alias->prev);
    return alias;
}

aliase_t *init_aliases(void)
{
    aliase_t *aliases = malloc(sizeof(aliase_t));
    FILE *file = NULL;

    if (aliases == NULL)
        return NULL;
    if ((file = _42rc_is_filled()) == NULL) {
        aliases->prev = NULL;
        if ((aliases->new_name = my_strdup("ls")) == NULL)
            return NULL;
        if ((aliases->command = my_strdup("ls")) == NULL)
            return NULL;
        aliases->next = NULL;
        return aliases;
    }
    if ((aliases = fill_42rc_since_file(aliases, file)) == NULL)
        return NULL;
    my_putstr(aliases->new_name);
    fclose(file);
    return aliases;
}
