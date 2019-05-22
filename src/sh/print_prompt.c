/*
** EPITECH PROJECT, 2019
** 42SH
** File description:
** print_prompt
*/

#include "shell.h"

void print_prompt(int fd)
{
    if (isatty(fd))
        my_printf("$> ");
}
