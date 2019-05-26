/*
** EPITECH PROJECT, 2019
** 42SH
** File description:
** reset_command
*/

#include "shell.h"

void reset_command(t_info *shell)
{
    if (shell->command_line != NULL) {
        free(shell->command_line);
        shell->command_line = NULL;
    }
    if (shell->path != NULL) {
        free(shell->path);
        shell->path = NULL;
    }
    shell->status = 0;
    shell->child_pid = 0;
    shell->fdd = 0;
    shell->fd[0] = 0;
    shell->fd[1] = 0;
}
