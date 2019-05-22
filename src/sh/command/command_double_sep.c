/*
** EPITECH PROJECT, 2019
** 42SH
** File description:
** command_double_sep
*/

#include "shell.h"

t_command *eval_double_sep(t_command *actual, int ret)
{
    if (!actual->next)
        return (NULL);
    if (ret == 0) {
        if (strcmp(actual->separator, "&&") == 0)
            return (actual->next);
        while (actual && strcmp(actual->separator, "||") == 0)
            actual = actual->next;
        return (actual);
    }
    if (ret != 0) {
        if (strcmp(actual->separator, "||") == 0)
            return (actual->next);
        while (actual && strcmp(actual->separator, "&&") == 0)
            actual = actual->next;
        return (actual);
    }
    actual = actual->next->next;
    return (actual);
}

int command_double_sep(t_command *command, t_info *shell)
{
    t_list *list = command_to_list_double_sep(command->command, "&&||\n\0");
    int ret = -1;

    if (list == NULL)
        return (RETURN_FAILURE);
    for (t_command *actual = list->start; actual;) {
        if ((ret = command_pip(actual, shell)) == RETURN_FAILURE) {
            delete_list(list);
            return (RETURN_FAILURE);
        }
        actual = eval_double_sep(actual, ret);
        if (actual == NULL) break;
    }
    delete_list(list);
    return (RETURN_SUCCESS);
}
