/*
** EPITECH PROJECT, 2019
** 42SH
** File description:
** delete_list
*/

#include "shell.h"

void delete_command(t_command *command)
{
    if (command->command)
        free(command->command);
    if (command->separator)
        free(command->separator);
    if (command->tab_command)
        command->tab_command = free_array(command->tab_command);
    free(command);
}

t_list *delete_list(t_list *list)
{
    if (list) {
        t_command *tmp = list->start;
        t_command *next = NULL;

        while (tmp) {
            next = tmp->next;
            delete_command(tmp);
            tmp = next;
        }
        free(list);
    }
    return (NULL);
}
