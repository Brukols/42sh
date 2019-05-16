/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** my_set
*/

#include "shell.h"

int my_set(t_info *shell, t_command *command)
{
    int verif;

    if ((verif = delete_all_quotation_set(command)) == UNMATCHED_QUOTE)
        return (EXIT_SUCCESS);
    if (verif == EXIT_FAILURE)
        return (EXIT_FAILURE);
    if (check_alphanumeric_name(command) == NOT_ALPHA_NUMERIC)
        return (EXIT_SUCCESS);
    for (int i = 1; command->tab_command[i]; i++) {
        if (set_variable(shell, command, i) == EXIT_FAILURE)
            return (EXIT_FAILURE);
    }
    return (EXIT_SUCCESS);
}