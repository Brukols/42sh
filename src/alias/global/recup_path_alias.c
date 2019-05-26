/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** alias
*/

#include "shell.h"

char *recup_path_alias(void)
{
    char *beg = getenv("HOME");
    char *end = "/.alias";
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
