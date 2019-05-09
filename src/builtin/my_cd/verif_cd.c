/*
** EPITECH PROJECT, 2019
** 42SH
** File description:
** verif_cd
*/

#include "shell.h"

int verif_cd(char **tab_command)
{
    if (get_size_array(tab_command) > 2) {
        my_printe("cd: Too many arguments\n");
        return -1;
    }
    return 0;
}
