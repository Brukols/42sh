/*
** EPITECH PROJECT, 2019
** 42SH
** File description:
** add_to_list
*/

#include "shell.h"

t_list *add_to_list(t_list *list, t_command *command)
{
    t_command *tmp = NULL;
    if (list->start == NULL) {
        list->start = command;
        list->len++;
        return (list);
    }
    tmp = list->start;
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = command;
    command->prev = tmp;
    list->len++;
    return (list);
}
