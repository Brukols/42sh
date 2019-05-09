/*
** EPITECH PROJECT, 2019
** 42SH
** File description:
** shell
*/

#include "shell.h"

int shell(char **env)
{
    t_info *shell = prepare_info(env);

    if (shell == NULL) {
        delete_all(shell);
        return (EXIT_ERROR);
    }

    prepare_signal();
    print_prompt();

    if (my_sh(shell) == EXIT_FAILURE) {
        delete_all(shell);
        return (EXIT_ERROR);
    }
    delete_all(shell);
    return (EXIT_SUCCESS);
}
