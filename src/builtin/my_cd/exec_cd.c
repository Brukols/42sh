/*
** EPITECH PROJECT, 2019
** 42SH
** File description:
** exec_cd
*/

#include "shell.h"

int exec_cd(t_info *shell, t_command *command)
{
    if (command->tab_command[1] == NULL) {
        char *home = search_env(shell->env, "HOME=");
        if (home == NULL || home[0] == '\0') {
            free(home);
            my_printe("cd: no home find in env.\n");
            return -1;
        } else if (change_dir(home) == -1) {
            free(home);
            return -1;
        }
        free(home);
    } else if (command->tab_command[1][0] == '-') {
        if (change_old_dir(shell) == -1)
            return -1;
    } else {
        if (change_dir(command->tab_command[1]) == -1)
            return -1;
    }
    return 0;
}
