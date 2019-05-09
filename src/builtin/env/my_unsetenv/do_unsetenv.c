/*
** EPITECH PROJECT, 2019
** 42SH
** File description:
** do_unsetenv
*/

#include "shell.h"

char **do_unsetenv(char **env, char *del)
{
    char *tmp = NULL;
    for (int i = 0; env != NULL && env[i] != NULL; i++) {
        tmp = my_strdup(env[i]);
        for (int j = 0; tmp[j] != '\0'; j++) {
            if (tmp[j] == '=')
                tmp[j] = '\0';
        }
        if (my_strcmp(tmp, del) == 0
        && my_strlen(tmp) == my_strlen(del)) {
            free(tmp);
            return (exec_unsetenv(env, i));
        }
        free(tmp);
    }
    return env;
}
