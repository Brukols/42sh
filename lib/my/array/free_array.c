/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** free_array
*/

#include "my.h"

char **free_array(char **array)
{
    if (array != NULL) {
        for (int i = 0; array[i] != NULL; i++)
            free(array[i]);
        free(array);
    }
    return (NULL);
}
