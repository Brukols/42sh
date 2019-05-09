/*
** EPITECH PROJECT, 2019
** 42SH
** File description:
** my_sh
*/

#include "shell.h"

int my_sh(t_info *shell)
{
    while ((shell->command_line = get_next_line(0)) != NULL) {
        if ((shell->env = repair_env(shell->env)) == NULL)
            return (EXIT_FAILURE);
        if (command_comma(shell) == EXIT_FAILURE)
            return (EXIT_FAILURE);
        reset_command(shell);
        if (shell->exit)
            return (EXIT_SUCCESS);
        print_prompt();
    }

    return (EXIT_SUCCESS);
}
