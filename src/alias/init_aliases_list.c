/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** aliases
*/

#include "shell.h"

aliase_t *init_aliases(void)
{
    aliase_t *aliases = malloc(sizeof(aliase_t));
    FILE *file = NULL;

    if (aliases == NULL)
        return NULL;
    aliases->prev = NULL;
    if ((aliases->new_name = my_strdup("vi")) == NULL)
        return NULL;
    if ((aliases->command = my_strdup("vim")) == NULL)
        return NULL;
    aliases->next = NULL;
    if ((file = _42rc_is_filled()) == NULL)
        return aliases;
    if ((aliases = fill_42rc_since_file(aliases, file)) == NULL)
        return NULL;
    fclose(file);
    return aliases;
}
