/*
** EPITECH PROJECT, 2019
** local_and_env_variable
** File description:
** 42SH
*/

#include "shell.h"

int change_if_variable(t_command *cmd, t_info *shell, int i)
{
    int verif;

    for (int a = 0; cmd->tab_command[i][a]; a++) {
        if (cmd->tab_command[i][a] != '$')
            continue;
        verif = remplace_variable(cmd, shell, i, a);
        if (verif == EXIT_FAILURE)
            return (EXIT_FAILURE);
        if (verif == EXIT_SUCCESS)
            return (EXIT_SUCCESS);
    }
    return (VARIABLE);
}

int local_and_env_variable(t_command *cmd, t_info *shell)
{
    int verif = 0;

    for (int i = 0; cmd->tab_command[i]; i++) {
        verif = change_if_variable(cmd, shell, i);
        if (verif == EXIT_FAILURE)
            return (EXIT_FAILURE);
        if (verif == EXIT_SUCCESS)
            return (EXIT_SUCCESS);
    }
    return (VARIABLE);
}