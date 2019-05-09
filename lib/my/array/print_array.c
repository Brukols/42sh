/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** print_array
*/

#include "my.h"

void print_array(char **array)
{
    for (int i = 0; array != NULL && array[i] != NULL; i++) {
        my_printf("%s\n", array[i]);
    }
}
