/*
** EPITECH PROJECT, 2019
** 42SH
** File description:
** exec_unsetenv
*/

#include "shell.h"

char **exec_unsetenv(char **env, int pos)
{
    int size = get_size_array(env);
    char **new_env = malloc(sizeof(char *) * size);
    if (new_env == NULL) {
        my_printe("malloc() failed, please_retry\n");
        return NULL;
    }
    for (int i = 0, j = 0; env != NULL && env[j] != NULL; i++, j++) {
        if (i == pos)
            j++;
        if (env[j] == NULL)
            break;
        else
            new_env[i] = my_strdup(env[j]);
    }
    new_env[size - 1] = NULL;
    free_array(env);
    return new_env;
}
