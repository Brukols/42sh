/*
** EPITECH PROJECT, 2019
** 42SH
** File description:
** pip_redirection
*/

#include "shell.h"

int pip_redirection(t_info *shell, t_command *command)
{
    if (dup2(shell->fdd, 0) == -1) {
        my_printe("%s\n", strerror(errno));
        return (RETURN_FAILURE);
    }
    if (command->next != NULL) {
        if (dup2(shell->fd[1], 1) == -1) {
            my_printe("%s\n", strerror(errno));
            return (RETURN_FAILURE);
        }
    }
    close(shell->fd[1]);
    close(shell->fd[0]);
    return (RETURN_SUCCESS);
}
