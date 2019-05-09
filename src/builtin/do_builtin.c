/*
** EPITECH PROJECT, 2019
** 42SH
** File description:
** do_builtin
*/

#include "shell.h"

int do_builtin(t_info *shell, int cmd_no, t_command *command)
{
    if (builtin_redirection(shell, command) == EXIT_FAILURE)
        return (EXIT_FAILURE);
    shell->builtin[cmd_no]->ft(shell, command);
    shell->fdd = shell->fd[0];
    if (dup2(shell->stdin_o, STDIN_FILENO) == -1
    || dup2(shell->stdou_o, STDOUT_FILENO) == -1) {
        my_printe("%s\n", strerror(errno));
        return (EXIT_FAILURE);
    }
    return (EXIT_SUCCESS);
}
