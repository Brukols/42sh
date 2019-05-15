/*
** EPITECH PROJECT, 2019
** local_and_env_variable
** File description:
** 42SH
*/

#include "shell.h"

char *recup_the_name(char *cmd)
{
    int i = 1;
    char *name = malloc(sizeof(char) * (my_strlen(cmd) + 1));

    if (!name)
        return (NULL);
    for (; cmd[i]; i++)
        name[i - 1] = cmd[i];
    name[i - 1] = '\0';
    return (name);
}

bool is_an_int(char *name)
{
    for (int i = 0; name[i]; i++) {
        if (name[i] < '0' || name[i] > '9')
            return (false);
    }
    return (true);
}

int change_variable(t_command *cmd, t_info *shell, int i)
{
    int verif;
    char *name = recup_the_name(cmd->tab_command[i]);

    if (!name)
        return (EXIT_FAILURE);
    free(cmd->tab_command[i]);
    cmd->tab_command[i] = my_strdup(name);
    if (!cmd->tab_command[i])
        return (EXIT_FAILURE);
    verif = cmd_has_a_value(cmd, shell, name, i);
    if (verif == EXIT_FAILURE)
        return (EXIT_FAILURE);
    if (verif == GOOD_VARIABLE)
        return (GOOD_VARIABLE);
    if (is_an_int(cmd->tab_command[i]) == false) {
        my_putstr(cmd->tab_command[i]);
        my_putstr(": Undefined variable.\n");
    }
    return (UNDEFINED_VARIABLE);
}

int local_and_env_variable(t_command *cmd, t_info *shell)
{
    int verif = 0;

    for (int i = 0; cmd->tab_command[i]; i++) {
        if (cmd->tab_command[i][0] != '$')
            continue;
        if (!cmd->tab_command[i][1])
            continue;
        verif = change_variable(cmd, shell, i);
        if (verif == EXIT_FAILURE)
            return (EXIT_FAILURE);
        if (verif == UNDEFINED_VARIABLE)
            return (UNDEFINED_VARIABLE);
    }
    return (GOOD_VARIABLE);
}