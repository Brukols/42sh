/*
** EPITECH PROJECT, 2019
** 42SH
** File description:
** right_redirection
*/

#include "shell.h"

int right_redirection(t_info *shell, t_command *command)
{
    int fd = 0;
    if (dup2(shell->fdd, 0) == -1) {
        my_printe("%s\n", strerror(errno));
        return (RETURN_FAILURE);
    }
    if (command->next == NULL || command->next->tab_command == NULL
    || (fd = open(command->next->tab_command[0],
    O_CREAT | O_RDWR, 0664)) == -1) {
        my_printe("Missing name for redirect.\n");
        return (RETURN_FAILURE);
    }
    if (dup2(fd, STDOUT_FILENO) == -1) {
        my_printe("%s\n", strerror(errno));
        return (RETURN_FAILURE);
    }
    close(fd);
    close(shell->fd[1]);
    close(shell->fd[0]);
    return (RETURN_SUCCESS);
}
