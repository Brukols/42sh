/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** create_array
*/

#include "my.h"

char **create_array(int rows, int cols)
{
    char **tab = malloc(sizeof(char *) * (rows + 1));

    if (tab == NULL) {
        my_printe("Malloc() failed, please retry\n");
        return NULL;
    }

    for (int i = 0; i < rows; i++) {
        tab[i] = malloc(sizeof(char) * (cols + 1));
        if (tab[i] == NULL) {
            my_printe("Malloc() failed, please retry\n");
            return NULL;
        }
        my_memset(tab[i], '\0', cols + 1);
    }
    tab[rows] = NULL;
    return tab;
}
