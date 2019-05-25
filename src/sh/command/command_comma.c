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
        return (RETURN_FAILURE);
    if (errno == UNMATCHED_QUOTE) {
        delete_list(list);
        return (RETURN_SUCCESS);
    }
    for (t_command *actual = list->start; actual; actual = actual->next) {
        if (command_double_sep(actual, shell) == RETURN_FAILURE) {
            delete_list(list);
            return (RETURN_FAILURE);
        }
        reset_comma(shell);
    }
    delete_list(list);
    return (RETURN_SUCCESS);
}
