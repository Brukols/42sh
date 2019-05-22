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

char *fill_next_cmd(char *str, int *i, char *sep)
{
    int a = 0;
    char *cmd = malloc(sizeof(char) * (my_strlen(str) + 1));

    if (!cmd)
        return (NULL);
    for (; str[*i] && is_a_separator(str[*i], sep) == false; (*i)++, a++) {
        if (str[*i] == '\\' && !str[*i + 1]) {
            *i += 1;
            break;
        }
        if (str[*i] == '\\' && str[*i + 1] != '$') {
            (*i)++;
            cmd[a] = str[*i];
            continue;
        }
        cmd[a] = str[*i];
    }
    cmd[a] = '\0';
    return (cmd);
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
    return (cmd);
}