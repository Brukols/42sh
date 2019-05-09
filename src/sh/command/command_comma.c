/*
** EPITECH PROJECT, 2019
** 42SH
** File description:
** command_comma
*/

#include "shell.h"

int command_comma(t_info *shell)
{
    t_list *list = command_to_list(shell->command_line, ";\n");
    if (list == NULL)
        return (EXIT_FAILURE);
    for (t_command *actual = list->start; actual; actual = actual->next) {
        if (command_pip(actual, shell) == EXIT_FAILURE) {
            delete_list(list);
            return (EXIT_FAILURE);
        }
        reset_comma(shell);
    }
    delete_list(list);
    return (EXIT_SUCCESS);
}
