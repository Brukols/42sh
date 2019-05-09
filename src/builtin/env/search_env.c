/*
** EPITECH PROJECT, 2019
** 42SH
** File description:
** search_env
*/

#include "shell.h"

char *search_env(char **env, char *search)
{
    char *find = NULL;

    for (int i = 0; env != NULL && env[i] != NULL; i++) {
        if (my_strncmp(env[i], search, my_strlen(search)) == 0) {
            find = my_strdup(env[i] + my_strlen(search));
            return find;
        }
    }
    return find;
}