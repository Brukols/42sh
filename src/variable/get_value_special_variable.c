/*
** EPITECH PROJECT, 2019
** get_value_special_vairable
** File description:
** 42SH
*/

#include "shell.h"

char *get_name_special_variable(char *name)
{
    if (strcmp(name, "term") == 0)
        return (my_strdup("TERM"));
    if (strcmp(name, "cwd") == 0)
        return (my_strdup("PWD"));
    return (NULL);
}

char **return_no_value(void)
{
    char **value = malloc(sizeof(char *) * 1);

    if (!value)
        return (NULL);
    value[0] = NULL;
    return (value);
}

char **get_value_special_variable(t_info *shell, char *name)
{
    char **value;
    char *tmp;

    tmp = get_name_special_variable(name);
    if (!tmp)
        return (NULL);
    if (!(value = get_value_in_env(shell, tmp))) {
        free(tmp);
        return (return_no_value());
    }
    free(tmp);
    return (value);
}