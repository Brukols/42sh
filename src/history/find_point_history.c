/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** find_point_history
*/

#include "shell.h"

int verif_point(char *command, int i)
{
    if (command[i] == '!') {
        if (command[i + 1] == '!')
            return (0);
        return (-1);
    }
    return (-1);
}

int find_point_history(char *command)
{
    for (int i = 0; command[i] != '\0'; i++) {
        if (verif_point(command, i) == 0)
            return (i);
    }
    return (-1);
}
