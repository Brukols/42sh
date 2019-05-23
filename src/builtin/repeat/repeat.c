/*
** EPITECH PROJECT, 2019
** 42SH
** File description:
** repeat
*/

#include "shell.h"

int my_repeat(t_info *shell, t_command *command)
{
    long int nb_loop = 0;
    char *endptr;

    if (get_size_array(command->tab_command) < 3)
        return (RETURN_FAILURE);
    nb_loop = strtol(command->tab_command[1], &endptr, 10);
    if (endptr[0] != '\0')
        return (RETURN_FAILURE);
    return (0);
}
