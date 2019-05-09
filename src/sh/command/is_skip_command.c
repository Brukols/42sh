/*
** EPITECH PROJECT, 2019
** 42SH
** File description:
** is_skip_command
*/

#include "shell.h"

int is_skip_command(t_command *command)
{
    if (command->prev) {
        if (my_strcmp(command->prev->separator, ">") == 0
            && my_strlen(command->prev->separator) == 1)
            return (1);
        if (my_strcmp(command->prev->separator, ">>") == 0
            && my_strlen(command->prev->separator) == 2)
            return (1);
        if (my_strcmp(command->prev->separator, "<") == 0
            && my_strlen(command->prev->separator) == 1)
            return (1);
        if (my_strcmp(command->prev->separator, "<<") == 0
            && my_strlen(command->prev->separator) == 2)
            return (1);
    }
    return (0);
}
