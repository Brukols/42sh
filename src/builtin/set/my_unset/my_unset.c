/*
** EPITECH PROJECT, 2019
** 42SH
** File description:
** my_unset
*/

#include "shell.h"

int delete_element(t_variable *var, t_info *shell)
{
    t_variable *tmp;

    free(var->name);
    free_array(var->arg);
    if (!var->prev && !var->next) {
        free(var);
        shell->variable = NULL;
        return (EXIT_SUCCESS);
    }
    tmp = var;
    if (var->prev)
        var->prev->next = var->next;
    if (var->next) {
        var->next->prev = var->prev;
        var = var->next;
    } else
        var = var->prev;
    free(tmp);
    for (; var->prev; var = var->prev);
    shell->variable = var;
    return (EXIT_SUCCESS);
}

int delete_variable(t_info *shell, char *str)
{
    t_variable *var = shell->variable;

    for (; var && strcmp(var->name, str); var = var->next);
    if (!var)
        return (EXIT_SUCCESS);
    return (delete_element(var, shell));
}

int my_unset(t_info *shell, t_command *command)
{
    for (int i = 1; command->tab_command[i]; i++)
        delete_variable(shell, command->tab_command[i]);
    return (EXIT_SUCCESS);
}