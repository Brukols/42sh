/*
** EPITECH PROJECT, 2019
** 42SH
** File description:
** shell
*/

#include "shell.h"

int shell(int argc, char **argv, char **env)
{
    t_info *shell = prepare_info(argc, argv, env);

    if (shell == NULL) {
        return (EXIT_ERROR);
    }
    prepare_signal();
    print_prompt(shell->fd_read);

    if (my_sh(shell) == RETURN_FAILURE) {
        delete_all(shell);
        return (EXIT_ERROR);
    }
    delete_all(shell);
    return (RETURN_SUCCESS);
}
