/*
** EPITECH PROJECT, 2019
** 42SH
** File description:
** get_right_path
*/

#include "shell.h"

int already_path(char *path)
{
    for (int i = 0; path[i]; i++)
        if (path[i] == '/')
            return (1);
    return (0);
}

int check_path(char *path)
{
    if (path == NULL)
        return -1;
    if (access(path, F_OK) == -1)
        return -1;
    return 0;
}

char *get_right_path(char *path, char **path_tab)
{
    char *right_path = my_strdup(path);
    int i = 0;
    if (already_path(right_path)) return (right_path);
    for (i = 0; check_path(right_path) == -1 && path_tab[i] != NULL; i++) {
        free(right_path);
        right_path = malloc(sizeof(char) * (my_strlen(path_tab[i])
        + my_strlen(path) + 2));
        if (right_path == NULL) {
            my_printe("malloc() failed, please_retry\n");
            return NULL;
        }
        my_strncpy(right_path, path_tab[i], my_strlen(path_tab[i]));
        my_strcat(right_path, "/");
        my_strcat(right_path, path);
    }
    if (check_path(right_path) == -1 && path_tab[i] == NULL) {
        free(right_path);
        return NULL;
    }
    return right_path;
}
