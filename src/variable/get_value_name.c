/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** get_value_name
*/

#include "shell.h"

char *get_next_env(char *env)
{
    int i = 0;
    char *name = malloc(sizeof(char) * (my_strlen(env) + 1));

    if (!name)
        return (NULL);
    for (; env[i] && env[i] != '='; i++)
        name[i] = env[i];
    name[i] = '\0';
    return (name);
}

char **get_value_env(char *env)
{
    int i = 0;
    int a = 0;
    char **arr;
    char *value = malloc(sizeof(char) * (my_strlen(env) + 1));

    if (!value)
        return (NULL);
    for (; env[i] != '='; i++);
    for (i++; env[i]; i++, a++)
        value[a] = env[i];
    value[a] = '\0';
    arr = my_str_to_word_array(value, ' ');
    if (!arr)
        return (NULL);
    free(value);
    return (arr);
}

char **get_value_in_env(t_info *shell, char *name)
{
    char **env = shell->env;
    char *next;

    for (int i = 0; env[i]; i++) {
        next = get_next_env(env[i]);
        if (!next)
            return (NULL);
        if (strcmp(next, name) == 0) {
            free(next);
            return (get_value_env(env[i]));
        }
        free(next);
    }
    return (NULL);
}

bool is_special_variable(char *name)
{
    char *all_name[] = {"term", "cwd", NULL};

    for (int i = 0; all_name[i]; i++) {
        if (strcmp(name, all_name[i]) == 0) {
            return (true);
        }
    }
    return (false);
}

char **get_value_name(t_info *shell, char *name)
{
    t_variable *var = shell->variable;

    if (is_special_variable(name) == true)
        return (get_value_special_variable(shell, name));
    for (; var; var = var->next) {
        if (strcmp(var->name, name) == 0)
            return (var->arg);
    }
    return (get_value_in_env(shell, name));
}