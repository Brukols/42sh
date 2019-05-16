/*
** EPITECH PROJECT, 2019
** 42SH
** File description:
** double_right_builtin_redirection
*/

#include "shell.h"

int double_right_builtin_redirection(t_info *shell, t_command *command)
{
    int fd = 0;
    if (dup2(shell->fdd, 0) == -1) {
        my_printe("%s\n", strerror(errno));
        return (RETURN_FAILURE);
    }
    if ((fd = open(command->next->tab_command[0],
        O_CREAT | O_RDWR | O_APPEND, 0664)) == -1)
        return (RETURN_FAILURE);
    if (dup2(fd, STDOUT_FILENO) == -1) {
        my_printe("%s\n", strerror(errno));
        return (RETURN_FAILURE);
    }
    close(shell->fd[1]);
    close(shell->fd[0]);
    return (RETURN_SUCCESS);
}
