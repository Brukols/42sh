/*
** EPITECH PROJECT, 2019
** 42SH
** File description:
** bg_process_redireciton
*/

#include "shell.h"

int bg_process_redirection(t_info *shell, t_command *cmd)
{
    shell->bg_process = true;
    printf("%d\n", getpid());
    shell->all_bg_process = add_bg_process(shell->all_bg_process, \
getpid());
    if (!shell->all_bg_process)
        return (RETURN_FAILURE);
    return (RETURN_SUCCESS);
}