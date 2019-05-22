/*
** EPITECH PROJECT, 2019
** 42SH
** File description:
** my_sh
*/

#include "shell.h"

int my_sh(t_info *shell)
{
    while ((shell->command_line = get_next_line(shell->fd_read)) != NULL) {
        if ((shell->env = repair_env(shell->env)) == NULL)
            return (EXIT_FAILURE);
        if (command_comma(shell) == RETURN_FAILURE)
            return (RETURN_FAILURE);
        reset_command(shell);
        if (shell->exit)
            return (RETURN_SUCCESS);
        print_prompt(shell->fd_read);
    }
    return (RETURN_SUCCESS);
}
