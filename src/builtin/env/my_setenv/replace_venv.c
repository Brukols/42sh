/*
** EPITECH PROJECT, 2019
** 42SH
** File description:
** replace_venv
*/

#include "shell.h"

char **replace_venv(char **env, char *name, char *value)
{
    env = do_unsetenv(env, name);
    env = add_venv(env, name, value);
    return env;
}
