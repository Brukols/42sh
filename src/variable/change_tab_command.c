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
    free(cmd->tab_command[i]);
    cmd->tab_command[i] = malloc(sizeof(char) * (my_strlen(tmp) + 1));
    if (!cmd->tab_command[i])
        return (EXIT_FAILURE);
    for (; tmp[n]; n++) {
        if (n == a)
            continue;
        cmd->tab_command[i][p] = tmp[n];
        p++;
    }
    cmd->tab_command[i][p] = '\0';
    free(tmp);
    return (EXIT_SUCCESS);
}

int delete_the_name(t_command *cmd, int i, int a)
{
    if (!(cmd->tab_command[i] = delete_one_chara(cmd->tab_command[i], a)))
        return (EXIT_FAILURE);
    while (cmd->tab_command[i][a] && is_alphanumeric(cmd->tab_command[i][a])) {
        if (!(cmd->tab_command[i] = delete_one_chara(cmd->tab_command[i], a)))
            return (EXIT_FAILURE);
    }
    return (EXIT_SUCCESS);
}

int change_tab_command(t_command *cmd, char **value, int i, int a)
{
    char *name = get_name_variable(cmd, i, a);

    if (!name)
        return (EXIT_FAILURE);
    if (delete_the_name(cmd, i, a) == EXIT_FAILURE)
        return (EXIT_FAILURE);
    if (replace_the_name(cmd, value, i) == EXIT_FAILURE)
        return (EXIT_FAILURE);
    if (strcmp(name, "term") == 0 || strcmp(name, "cwd") == 0)
        free_array(value);
    free(name);
    if (my_strlen(cmd->tab_command[0]) == 0)
        return (EXIT_SUCCESS);
    return (VARIABLE);
}