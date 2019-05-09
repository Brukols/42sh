/*
** EPITECH PROJECT, 2019
** 42SH
** File description:
** verif_env
*/

#include "shell.h"

int verif_arg_env(char **arg)
{
    if (get_size_array(arg) > 3) {
        my_printe("setenv : Too many arguments\n");
        return 1;
    }
    if (get_size_array(arg) == 1) {
        return 0;
    }
    for (int i = 0; arg[1][i]; i++) {
        if (!(('0' <= arg[1][i] && arg[1][i] <= '9')
        || ('a' <= arg[1][i] && arg[1][i] <= 'z')
        || ('A' <= arg[1][i] && arg[1][i] <= 'Z'))) {
            my_printe("setenv: Variable name must contain"\
            " alphanumeric characters.\n");
            return 1;
        }
    }
    return 0;
}
