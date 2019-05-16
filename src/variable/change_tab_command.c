/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** change_tab_comand
*/

#include "shell.h"

int delete_character(t_command *cmd, int i, int a)
{
    int n = 1;
    int p = 0;
    char *tmp = my_strdup(cmd->tab_command[i]);

    if (!tmp)
        return (EXIT_FAILURE);
    cmd->tab_command[i] = malloc(sizeof(char) * (my_strlen(tmp) + 1));
    if (!cmd->tab_command[i])
        return (EXIT_FAILURE);
    for (; tmp[n]; n++, p++) {
        if (p == a)
            continue;
        cmd->tab_command[i][p] = tmp[n];
        n++;
    }
    cmd->tab_command[i][p] = '\0';
    free(tmp);
    return (EXIT_SUCCESS);
}

int delete_the_name(t_command *cmd, int i, int a)
{
    if (delete_character(cmd, i, a) == EXIT_FAILURE)
        return (EXIT_FAILURE);
    while (is_alphanumeric(cmd->tab_command[i][a])) {
        if (delete_character(cmd, i, a) == EXIT_FAILURE)
            return (EXIT_FAILURE);
    }
    return (EXIT_SUCCESS);
}

int change_tab_command(t_command *cmd, char **value, int i, int a)
{
    if (delete_the_name(cmd, i, a) == EXIT_FAILURE)
        return (EXIT_FAILURE);
    if (remplace_the_name(cmd, value, i) == EXIT_FAILURE)
        return (EXIT_FAILURE);
    return (EXIT_SUCCESS);
}