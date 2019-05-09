/*
** EPITECH PROJECT, 2019
** 42SH
** File description:
** reset_redirect
*/

#include "shell.h"

void reset_redirect(t_info *shell)
{
    if (shell->path) {
        free(shell->path);
        shell->path = NULL;
    }
    shell->child_pid = 0;
    shell->status = 0;
}
