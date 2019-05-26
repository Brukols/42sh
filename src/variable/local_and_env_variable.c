/*
** EPITECH PROJECT, 2019
** local_and_env_variable
** File description:
** 42SH
*/

#include "shell.h"

int pass_inhib(t_command *cmd, int i, int *a)
{
    if (cmd->tab_command[i][*a] != '\\')
        return (SUCCESS);
    if (cmd->tab_command[i][*a + 1] == '$') {
        cmd->tab_command[i] = delete_one_chara(cmd->tab_command[i], *a);
        if (!cmd->tab_command[i])
            return (EXIT_FAILURE);
        (*a)++;
    }
    return (SUCCESS);
}

int change_if_variable(t_command *cmd, t_info *shell, int i)
{
    int verif;

    for (int a = 0; cmd->tab_command[i][a]; a++) {
        if (pass_inhib(cmd, i, &a) == EXIT_FAILURE)
            return (EXIT_FAILURE);
        if (!cmd->tab_command[i][a])
            break;
        if (cmd->tab_command[i][a] != '$')
            continue;
        verif = replace_variable(cmd, shell, i, a);
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