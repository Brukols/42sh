/*
** EPITECH PROJECT, 2019
** 42SH
** File description:
** create_tab_command
*/

#include "shell.h"

t_list *create_tab_command(t_list *list)
{
    t_command *tmp = list->start;

    errno = 0;
    while (tmp) {
        errno = 0;
        tmp->tab_command = command_in_array(tmp->command, " \t");
        if (tmp->tab_command == NULL)
            return NULL;
        tmp = tmp->next;
    }
    return (list);
}
