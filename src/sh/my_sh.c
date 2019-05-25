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
        shell->command_line = check_point_history(shell->command_line);
        add_in_history(shell->command_line);
        if (command_comma(shell) == RETURN_FAILURE)
            return (RETURN_FAILURE);
        reset_command(shell);
        if (shell->exit)
            return (RETURN_SUCCESS);
        print_prompt(shell);
    }
    return (RETURN_SUCCESS);
}
