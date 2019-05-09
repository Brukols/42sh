/*
** EPITECH PROJECT, 2019
** 42SH
** File description:
** signal_handler
*/

#include "shell.h"

void sigint_handler(int sig)
{
    (void)sig;
    if (isatty(0))
        my_printf("\n$> ");
    else
        my_printf("\n");
}
