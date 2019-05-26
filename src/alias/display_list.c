/*
** EPITECH PROJECT, 2019
** alias
** File description:
** 42sh
*/

#include "shell.h"

void display_alias(aliase_t *alias)
{
    for (; alias->prev; alias = alias->prev);
    for (; alias->next; alias = alias->next) {
        if (my_strcmp(alias->new_name, "vi") == 0)
            continue;
        printf("%s %s\n", alias->new_name, alias->command);
    }
    if (my_strcmp(alias->new_name, "vi") != 0)
        printf("%s %s\n", alias->new_name, alias->command);
    fflush(stdout);
    for (; alias->prev; alias = alias->prev);
}
