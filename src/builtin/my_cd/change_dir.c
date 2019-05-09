/*
** EPITECH PROJECT, 2019
** 42SH
** File description:
** change_dir
*/

#include "shell.h"

int change_dir(char *dir)
{
    if (access(dir, F_OK) == -1) {
        my_printe("%s: No such file or directory.\n", dir);
        return -1;
    }
    if (access(dir, R_OK) == -1) {
        my_printe("%s: Permission denied.\n", dir);
        return -1;
    }
    if (chdir(dir) == -1) {
        my_printe("%s: Not a directory.\n", dir);
        return -1;
    }
    return 0;
}
