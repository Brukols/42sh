/*
** EPITECH PROJECT, 2019
** 42SH
** File description:
** command_pip
*/

#include "shell.h"

int command_pip(t_command *command, t_info *shell)
{
    t_list *list = command_to_list(command->command, "|<>\n");
    if (list == NULL)
        return (EXIT_FAILURE);

    if ((list = create_tab_command(list)) == NULL)
        return (EXIT_FAILURE);
    if (list->start == NULL)
        my_printe("Invalid null command.\n");

    for (t_command *actual = list->start; actual; actual = actual->next) {
        reset_redirect(shell);
        if (parse_command(actual, shell) == EXIT_FAILURE) {
            delete_list(list);
            return (EXIT_FAILURE);
        }
    }
    wait_end_all_exec(shell);
    delete_list(list);
    return (EXIT_SUCCESS);
}
