/*
** EPITECH PROJECT, 2019
** 42SH
** File description:
** add_venv
*/

#include "shell.h"

char **add_venv(char **env, char *name, char *value)
{
    int size = get_size_array(env);
    char **new_env = malloc(sizeof(char *) * (size + 2));
    char *new_v = malloc(sizeof(char) * (my_strlen(name)
    + my_strlen(value) + 2));
    if (new_env == NULL || new_v == NULL) {
        my_printe("malloc() failed, please_retry\n");
        return env;
    }
    create_venv(new_v, name, value);
    for (size = 0; env != NULL && env[size] != NULL; size++) {
        new_env[size] = my_strdup(env[size]);
        if (new_env[size] == NULL) {
            my_printe("malloc() failed, please_retry\n");
            return env;
        }
    }
    new_env[size] = new_v;
    new_env[size + 1] = NULL;
    free_array(env);
    return new_env;
}
