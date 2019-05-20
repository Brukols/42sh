/*
** EPITECH PROJECT, 2019
** 42SH
** File description:
** charck azlpahnumeric my_set
*/

#include "shell.h"

bool name_is_alphanumeric(char *str)
{
    if ((str[0] <= '9' && str[0] >= '0') || str[0] == '=') {
        my_putstr("set: Variable name must begin with a letter.\n");
        return (false);
    }
    for (int i = 0; str[i] && str[i] != '='; i++) {
        if ((str[i] >= '0' && str[i] <= '9') || (str[i] >= 'a' && \
str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') || str[i] == '=')
            continue;
        my_putstr("set: Variable name must contain alphanumeric characters.");
        return (false);
    }
    return (true);
}

int check_alphanumeric_name(t_command *cmd)
{
    for (int i = 1; cmd->tab_command[i]; i++) {
        if (name_is_alphanumeric(cmd->tab_command[i]) == false)
            return (NOT_ALPHA_NUMERIC);
    }
    return (EXIT_SUCCESS);
}