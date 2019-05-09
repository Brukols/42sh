/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** my_array_cpy
*/

#include "my.h"

char **my_array_cpy(char **array)
{
    int i = get_size_array(array);
    char **new_array = malloc(sizeof(char *) * (i + 1));

    if (new_array == NULL)
        return NULL;
    for (i = 0; array[i] != NULL; i++) {
        new_array[i] = my_strdup(array[i]);
    }
    new_array[i] = NULL;
    return new_array;
}
