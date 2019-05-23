/*
** EPITECH PROJECT, 2019
** delete_line_array
** File description:
** lib
*/

#include "my.h"

char **delete_line_array(char **arr, int i)
{
    int b = 0;
    char **tmp = my_arraydup(arr);

    if (!tmp)
        return (NULL);
    free_array(arr);
    if (!(arr = malloc(sizeof(char *) * (my_arraylen(tmp) + 1))))
        return (NULL);
    for (int a = 0; tmp[a]; a++) {
        if (a == i)
            continue;
        if (!(arr[b] = my_strdup(tmp[a])))
            return (NULL);
        b++;
    }
    arr[b] = NULL;
    free_array(tmp);
    return (arr);
}
