/*
** EPITECH PROJECT, 2019
** 42SH
** File description:
** prepare_info
*/

#include "shell.h"

t_info *prepare_info(char **env)
{
    t_info *shell = malloc(sizeof(t_info));
    if (shell == NULL) return (NULL);
    shell->variable = NULL;
    if ((shell->builtin = init_builtin()) == NULL) return (NULL);
    shell->history = -1;
    shell->command_line = NULL;
    shell->path = NULL;
    shell->env = my_array_cpy(env);
    if (shell->env == NULL)
        return (delete_all(shell));
    if ((shell->history = init_history()) == -1)
        return (delete_all(shell));
    shell->exit = 0;
    shell->status = 0;
    shell->child_pid = 0;
    shell->fdd = 0;
    shell->stdin_o = dup(STDIN_FILENO);
    shell->stdou_o = dup(STDOUT_FILENO);
    return (shell);
}
