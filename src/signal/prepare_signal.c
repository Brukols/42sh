/*
** EPITECH PROJECT, 2019
** 42SH
** File description:
** prepare_signal
*/

#include "shell.h"

int prepare_signal(void)
{
    signal(SIGINT, sigint_handler);
    return 0;
}
