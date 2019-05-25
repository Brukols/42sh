/*
** EPITECH PROJECT, 2019
** 42SH
** File description:
** command_pip
*/

#include "shell.h"

int command_pip(t_command *command, t_info *shell)
{
    int ret = 0;

    t_list *list = command_to_list(command->command, "|<>\n");
    if (list == NULL)
        return (EXIT_FAILURE);
    if ((list = create_tab_command(list)) == NULL)
        return (RETURN_FAILURE);
    if (list->start == NULL || (list->len == 1 && list->start->command[0] == 0))
        my_printe("Invalid null command.\n");

    for (t_command *actual = list->start; actual; actual = actual->next) {
        reset_redirect(shell);
        if (parse_command(actual, shell) == RETURN_FAILURE) {
            delete_list(list);
            return (RETURN_FAILURE);
        }
    }
    ret = wait_end_all_exec(shell);
    delete_list(list);
    return (ret);
}
