/*
** EPITECH PROJECT, 2019
** 42SH
** File description:
** command in array
*/

#include "shell.h"

bool is_a_separator(char c, char *sep)
{
    for (int i = 0; sep[i]; i++) {
        if (sep[i] == c)
            return (true);
    }
    return (false);
}

char *fill_cmd(char *str, int *i, char *cmd, int *a)
{
    char quote;

    if (str[*i] != '"' && str[*i] != '\'') {
        cmd[*a] = str[*i];
        return (cmd);
    }
    quote = str[*i];
    (*i)++;
    for (; str[*i] && str[*i] != quote; (*i)++, (*a)++)
        cmd[*a] = str[*i];
    *a -= 1;
    if (!str[*i]) {
        *i -= 1;
        *a -= 1;
    }
    return (cmd);
}

char *fill_next_cmd(char *str, int *i, char *sep)
{
    int a = 0;
    char *cmd = malloc(sizeof(char) * (my_strlen(str) + 1));

    if (!cmd)
        return (NULL);
    for (; str[*i] && is_a_separator(str[*i], sep) == false; (*i)++, a++) {
        if (str[*i] == '\\' && !str[*i + 1]) {
            *i += 1;
            cmd[a] = str[*i];
            a++;
            break;
        }
        if (str[*i] == '\\' && str[*i + 1] != '$') {
            (*i)++;
            cmd[a] = str[*i];
            continue;
        }
        cmd = fill_cmd(str, i, cmd, &a);
    }
    cmd[a] = '\0';
    return (cmd);
}

char **delete_empty_command(char **arr)
{
    for (int i = 0; arr[i]; i++) {
        if (my_strlen(arr[i]) == 0) {
            arr = delete_line_array(arr, i);
            i--;
        }
        if (!arr)
            return (NULL);
    }
    return (arr);
}

char **command_in_array(char *str, char *sep)
{
    int i = 0;
    int a = 0;
    char **cmd = malloc(sizeof(char *) * 2);

    if (!cmd)
        return (NULL);
    cmd[i] = NULL;
    while (str[a]) {
        for (; is_a_separator(str[a], sep) == true; a++);
        if (!str[a])
            break;
        cmd[i] = fill_next_cmd(str, &a, sep);
        if (!cmd[i])
            return (NULL);
        cmd[i + 1] = NULL;
        cmd = my_realloc_array(cmd, 1);
        if (!cmd)
            return (NULL);
        i++;
    }
    return (delete_empty_command(cmd));
}