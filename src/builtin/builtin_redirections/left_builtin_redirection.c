/*
** EPITECH PROJECT, 2019
** 42SH
** File description:
** left_builtin_redirection
*/

#include "shell.h"

int left_builtin_redirection(t_info *shell, t_command *command)
{
    int fd = 0;
    if ((fd = open(command->next->tab_command[0], O_RDONLY)) == -1) {
        my_printe("%s\n", strerror(errno));
        return (RETURN_FAILURE);
    }
    if (dup2(fd, 0) == -1) {
        my_printe("%s\n", strerror(errno));
        return (RETURN_FAILURE);
    }
    if (command->next->next != NULL) {
        if (dup2(shell->fd[1], 1) == -1) {
            my_printe("%s\n", strerror(errno));
            return (RETURN_FAILURE);
        }
    }
    close(fd);
    close(shell->fd[1]);
    close(shell->fd[0]);
    return (RETURN_SUCCESS);
}
