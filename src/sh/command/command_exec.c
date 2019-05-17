/*
** EPITECH PROJECT, 2019
** 42SH
** File description:
** command_exec
*/

#include "shell.h"

int command_exec(t_command *command, t_info *shell)
{
    int cmd_no = 0;
    if (pipe(shell->fd) == -1) {
        my_printe("%s\n", strerror(errno));
        return (RETURN_FAILURE);
    }
    if ((cmd_no = is_builtin(command->tab_command[0], shell->builtin)) != -1) {
        if (do_builtin(shell, cmd_no, command) == RETURN_FAILURE)
            return (RETURN_FAILURE);
        return (RETURN_SUCCESS);
    }
    if (do_execve(shell, command) == RETURN_FAILURE)
        return (RETURN_FAILURE);
    return (RETURN_SUCCESS);
}
