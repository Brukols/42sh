/*
** EPITECH PROJECT, 2019
** 42SH
** File description:
** replace the name
*/

#include "shell.h"

char *concat_the_first_line(char *dest, char *src)
{
    int size = my_strlen(dest) + my_strlen(src);
    char *tmp = NULL;

    if (dest) {
        if (!(tmp = my_strdup(dest)))
            return (NULL);
        free(dest);
    }
    if (!(dest = malloc(sizeof(char) * (size + 3))))
        return (NULL);
    dest[0] = '\0';
    if (tmp) {
        dest = strcat(dest, tmp);
        free(tmp);
    }
    dest = strcat(dest, src);
    return (dest);
}

char **add_the_value(char **arr, char **tmp, int i, char *value)
{
    int a = 0;
    int n = 0;

    for (; tmp[a]; a++, n++) {
        if (!(arr[n] = my_strdup(tmp[a])))
            return (NULL);
        if (a != i)
            continue;
        n++;
        if (!(arr[n] = my_strdup(value)))
            return (NULL);
    }
    if (a == i) {
        n++;
        if (!(arr[n] = my_strdup(value)))
            return (NULL);
        n++;
    }
    arr[n] = NULL;
    return (arr);
}

char **add_a_line(char **arr, char *value, int i)
{
    char **tmp = my_array_cpy(arr);

    free_array(arr);
    if (!tmp)
        return (NULL);
    if (!(arr = malloc(sizeof(char *) * (get_size_array(tmp) + 2))))
        return (NULL);
    if (!(arr = add_the_value(arr, tmp, i, value)))
        return (NULL);
    free_array(tmp);
    return (arr);
}

int replace_the_name(t_command *cmd, char **value, int i)
{
    if (!value[0])
        return (EXIT_SUCCESS);
    cmd->tab_command[i] = concat_the_first_line(cmd->tab_command[i], value[0]);
    if (!cmd->tab_command[i])
        return (EXIT_FAILURE);
    for (int n = 1; value[n]; n++, i++) {
        cmd->tab_command = add_a_line(cmd->tab_command, value[n], i);
        if (!cmd->tab_command)
            return (EXIT_FAILURE);
    }
    return (EXIT_SUCCESS);
}