/*
** EPITECH PROJECT, 2019
** 42SH
** File description:
** get_separator
*/

#include "shell.h"

t_command *get_separator_double(t_command *command, char *str, char *sep, int i)
{
    int len_sep = 0;

    for (; str[i] != '\0' && (!check_sep_double(str, i, sep)
    || check_sep_double(str, i + 1, sep)); i++, len_sep++);
    command->separator = malloc(sizeof(char) * len_sep + 2);
    if (command->separator == NULL)
        return (NULL);
    my_strncpy(command->separator, &str[i - len_sep + 1], len_sep + 1);
    return (command);
}
