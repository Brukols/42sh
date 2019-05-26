/*
** EPITECH PROJECT, 2019
** 42SH
** File description:
** delete_all
*/

#include "shell.h"

void *delete_all(t_info *shell)
{
    if (!shell)
        return (NULL);
    delete_builtin(shell->builtin);
    delete_aliases(shell->aliases);
    delete_var(shell->variable);
    if (shell->env)
        free_array(shell->env);
    if (shell->command_line)
        free(shell->command_line);
    if (shell->path)
        free(shell->path);
    if (shell->fd_read != 0)
        close(shell->fd_read);
    free(shell);
    return (NULL);
}
