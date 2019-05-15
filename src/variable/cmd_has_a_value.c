/*
** EPITECH PROJECT, 2019
** 42SH
** File description:
** cmd_has_a_value
*/

#include "shell.h"

int change_value_cmd_env(t_command *cmd, char *env, int i)
{
    int a = 0;
    int n = 0;
    char *new_value = malloc(sizeof(char) * (my_strlen(env) + 1));

    if (!new_value)
        return (EXIT_FAILURE);
    free(cmd->tab_command[i]);
    for (; env[a] != '='; a++);
    a++;
    for (; env[a]; a++, n++)
        new_value[n] = env[a];
    new_value[n] = '\0';
    cmd->tab_command[i] = my_strdup(new_value);
    if (!cmd->tab_command[i])
        return (EXIT_FAILURE);
    free(new_value);
    return (GOOD_VARIABLE);
}

char *next_env(char *env)
{
    int i = 0;
    char *next = malloc(sizeof(char) * (my_strlen(env) + 1));

    if (!next)
        return (NULL);
    for (; env[i] != '='; i++)
        next[i] = env[i];
    next[i] = '\0';
    return (next);
}

int cmd_is_in_env(t_command *cmd, t_info *shell, char *name, int i)
{
    char **env = shell->env;
    char *next;

    for (int a = 0; env[a]; a++) {
        next = next_env(env[a]);
        if (!next)
            return (EXIT_FAILURE);
        if (strcmp(next, name) == 0)
            return (change_value_cmd_env(cmd, env[a], i));
        free(next);
    }
    return (EXIT_SUCCESS);
}

int cmd_is_in_variable(t_command *cmd, t_info *shell, char *name, int i)
{
    t_variable *var = shell->variable;

    for (; var; var = var->next) {
        if (strcmp(var->name, name) != 0)
            continue;
        free(cmd->tab_command[i]);
        cmd->tab_command[i] = my_strdup(var->value);
        if (!cmd->tab_command[i])
            return (EXIT_FAILURE);
        return (GOOD_VARIABLE);
    }
    return (UNDEFINED_VARIABLE);
}

int cmd_has_a_value(t_command *cmd, t_info *shell, char *name, int i)
{
    int verif;

    verif = cmd_is_in_env(cmd, shell, name, i);
    if (verif == EXIT_FAILURE)
        return (EXIT_FAILURE);
    if (verif == GOOD_VARIABLE)
        return (GOOD_VARIABLE);
    return (cmd_is_in_variable(cmd, shell, name, i));
}