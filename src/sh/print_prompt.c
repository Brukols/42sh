/*
** EPITECH PROJECT, 2019
** 42SH
** File description:
** print_prompt
*/

#include "shell.h"

void print_prompt(t_info *shell)
{
    char *logname = search_env(shell->env, "LOGNAME=");
    if (logname != NULL)
        my_printf("(%s) ", logname);
    if (isatty(shell->fd_read))
        my_printf("$> ");
    free(logname);
}
