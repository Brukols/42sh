/*
** EPITECH PROJECT, 2019
** 42SH
** File description:
** reset_comma
*/

#include "shell.h"

void reset_comma(t_info *shell)
{
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
