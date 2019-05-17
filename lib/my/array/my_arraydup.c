/*
** EPITECH PROJECT, 2019
** my_arraydup
** File description:
** lib
*/

#include "my.h"

int nb_line(char **arr)
{
    int nb_line = 0;

    if (!arr)
        return (nb_line);
    for (; arr[nb_line]; nb_line++);
    return (nb_line + 1);
}

char **my_arraydup(char **arr)
{
    int i = 0;
    char **cpy = malloc(sizeof(char *) * (nb_line(arr)));

    if (!arr)
        return (NULL);
    for (; arr[i]; i++) {
        if (!(cpy[i] = my_strdup(arr[i])))
            return (NULL);
    }
    cpy[i] = NULL;
    return (cpy);
}
