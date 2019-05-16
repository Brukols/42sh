/*
** EPITECH PROJECT, 2019
** 42SH
** File description:
** command_double_sep
*/

#include "shell.h"

int command_double_sep(t_command *command, t_info *shell)
{
    t_list *list = command_to_list_double_sep(command->command, "&&||\n\0");

    if (list == NULL)
        return (RETURN_FAILURE);
    for (t_command *actual = list->start; actual; actual = actual->next) {
        if (command_pip(actual, shell) == RETURN_FAILURE) {
            delete_list(list);
            return (RETURN_FAILURE);
        }
    }
    delete_list(list);
    return (RETURN_SUCCESS);
}
