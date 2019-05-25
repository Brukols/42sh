/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** check_point_history
*/

#include "shell.h"

char *stock_next(char *command_line, int pos)
{
    char *tmp = malloc(sizeof(char) * (strlen(command_line) - pos + 1));
    int i = 0;
    int j = 0;

    if (tmp == NULL)
        return (NULL);
    for (i = pos + 2; command_line[i] != '\0' || command_line[i] != '\n'; i++) {
        tmp[j] = command_line[i];
        j++;
    }
    tmp[j] = '\0';
    return (tmp);
}

char *transform_point_in_command(char *command_line, int pos)
{
    char *history = recup_last_command();
    char *end;
    char *beg;
    char *command;
    if (history == NULL)
        return (NULL);
    beg = strndup(command_line, pos);
    end = strdup(&command_line[pos + 2]);
    if ((command = malloc(sizeof(char) * (strlen(beg) + strlen(end) +
        strlen(history) + 1))) == NULL)
        return (NULL);
    command[0] = '\0';
    strcat(command, beg);
    strcat(command, history);
    strcat(command, end);
    free(beg);
    free(history);
    free(end);
    free(command_line);
    return (command);
}

char *check_point_history(char *command_line)
{
    int pos = find_point_history(command_line);
    char *tmp;

    if (pos == -1)
        return (command_line);
    if ((tmp = transform_point_in_command(command_line, pos)) == NULL)
        return (command_line);
    while ((pos = find_point_history(tmp)) != -1) {
        tmp = transform_point_in_command(tmp, pos);
    }
    my_printf("%s\n", tmp);
    return (tmp);
}