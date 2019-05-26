/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** alias
*/

#include "shell.h"

t_command *global_alias(t_command *command, t_info *shell)
{
    FILE *file = NULL;

    if ((file = alias_is_filled()) == NULL)
        return command;
    if ((shell->aliases = fill_alias_since_file(shell->aliases, file)) == NULL)
        return NULL;
    if ((command = change_command_line(shell, command)) == NULL)
        return NULL;
    return command;
}
