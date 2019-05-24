/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** recup_path_history
*/

#include "shell.h"

char *recup_path_history(void)
{
    char *beg = getenv("HOME");
    char *end = "/.history_42sh";
    char *buffer;

    if (beg == NULL)
        return (NULL);
    buffer = malloc(sizeof(char) * (my_strlen(beg) + my_strlen(end) + 1));
    if (buffer == NULL)
        return (NULL);
    buffer = my_strcpy(buffer, beg);
    buffer = my_strcat(buffer, end);
    return (buffer);
}