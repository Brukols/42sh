/*
** EPITECH PROJECT, 2019
** 42SH
** File description:
** do_execve
*/

#include "shell.h"

int do_execve(t_info *shell, t_command *command)
{
    if ((shell->child_pid = create_process()) == -1) {
        perror("fork :");
        return (RETURN_FAILURE);
    } else if (shell->child_pid == 0) {
        if (child_redirection(shell, command) == RETURN_FAILURE)
            return (RETURN_FAILURE);
        child_process(shell, command);
    } else {
        close(shell->fd[1]);
        shell->fdd = shell->fd[0];
    }
    return (RETURN_SUCCESS);
}
