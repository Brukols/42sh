/*
** EPITECH PROJECT, 2019
** 42SH
** File description:
** my_env
*/

#include "shell.h"

int my_env(t_info *shell, t_command *command)
{
    (void)command;
    print_array(shell->env);
    return 0;
}
