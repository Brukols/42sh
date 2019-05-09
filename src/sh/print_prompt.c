/*
** EPITECH PROJECT, 2019
** 42SH
** File description:
** print_prompt
*/

#include "shell.h"

void print_prompt(void)
{
    if (isatty(0))
        my_printf("$> ");
}
