/*
** EPITECH PROJECT, 2019
** 42SH
** File description:
** exit
*/

#include "shell.h"

int my_exit(t_info *shell, t_command *command)
{
    (void)command;
    shell->exit = 1;
    return (RETURN_SUCCESS);
}
