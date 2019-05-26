/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** alias
*/

#include "shell.h"

bool show_one_alias(char **tab_command, t_info *shell)
{
    aliase_t *alias = shell->aliases;

    if (my_arraylen(tab_command) != 2)
        return false;
    if (my_strcmp(tab_command[0], "alias") != 0)
        return false;
    for (; alias->prev; alias = alias->prev);
    for (; alias->next; alias = alias->next) {
        if (my_strcmp(tab_command[1], alias->new_name) == 0) {
            my_putstr(alias->command);
            my_putchar('\n');
            return true;
        }
    }
    if (my_strcmp(tab_command[1], alias->new_name) == 0) {
        my_putstr(alias->command);
        return true;
    }
    return false;
}
