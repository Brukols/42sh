/*
** EPITECH PROJECT, 2019
** my_realloc_array
** File description:
** lib
*/

#include "my.h"

char **my_realloc_array(char **arr, int a)
{
    int i = 0;
    char **tmp = my_arraydup(arr);

    if (!tmp)
        return (NULL);
    free_array(arr);
    if (!(arr = malloc(sizeof(char *) * (my_arraylen(tmp) + a + 1))))
        return (NULL);
    for (; tmp[i]; i++) {
        if (!(arr[i] = my_strdup(tmp[i])))
            return (NULL);
    }
    arr[i] = NULL;
    free_array(tmp);
    return (arr);
}