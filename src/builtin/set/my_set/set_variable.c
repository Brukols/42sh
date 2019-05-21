/*
** EPITECH PROJECT, 2019
** 42SH
** File description:
** set_variable
*/

#include "shell.h"

char *get_name_set(char *str)
{
    int i = 0;
    char *name = malloc(sizeof(char) * (my_strlen(str) + 1));

    if (!name)
        return (NULL);
    for (; str[i] && str[i] != '='; i++)
        name[i] = str[i];
    name[i] = '\0';
    return (name);
}

t_variable *add_variable(t_info *shell, char *name)
{
    t_variable *var = shell->variable;

    if (!var) {
        var = malloc(sizeof(t_variable));
        if (!var)
            return (NULL);
        var->prev = NULL;
        var->next = NULL;
    } else {
        for (; var->next; var = var->next);
        var->next = malloc(sizeof(t_variable));
        if (!var->next)
            return (NULL);
        var->next->prev = var;
        var = var->next;
        var->next = NULL;
    }
    var->name = my_strdup(name);
    if (!var->name)
        return (NULL);
    return (var);
}

char *get_value_set(char *str)
{
    int i = 0;
    int a = 0;
    char *value = malloc(sizeof(char) * (my_strlen(str) + 1));

    if (!value)
        return (NULL);
    value[0] = '\0';
    for (; str[i] && str[i] != '='; i++);
    if (!str[i] || !str[i + 1])
        return (value);
    for (i++; str[i]; i++, a++)
        value[a] = str[i];
    value[a] = '\0';
    return (value);
}

int complete_value(t_variable *var, t_command *cmd, t_info *shell, int i)
{
    char *original_value = get_value_set(cmd->tab_command[i]);

    if (!original_value)
        return (EXIT_FAILURE);
    var->arg = my_str_to_word_array(original_value, ' ');
    free(original_value);
    if (!var->arg)
        return (EXIT_FAILURE);
    for (; var->prev; var = var->prev);
    shell->variable = var;
    return (EXIT_SUCCESS);
}

int set_variable(t_info *shell, t_command *cmd, int i)
{
    char *name = get_name_set(cmd->tab_command[i]);
    t_variable *var = shell->variable;

    if (!name)
        return (EXIT_FAILURE);
    for (; var && strcmp(var->name, name) != 0; var = var->next);
    if (!var) {
        if (!(var = add_variable(shell, name)))
            return (EXIT_FAILURE);
    }
    free(name);
    return (complete_value(var, cmd, shell, i));
}