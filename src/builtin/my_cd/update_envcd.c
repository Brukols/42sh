/*
** EPITECH PROJECT, 2019
** 42SH
** File description:
** update_envcd
*/

#include "shell.h"

int update_envcd(t_info *shell, char *old_pwd)
{
    char *actual_pwd = malloc(sizeof(char) * PATH_MAX + 1);
    if (actual_pwd == NULL) {
        my_printe("malloc() failed, please_retry\n");
        free(old_pwd);
        return -1;
    }
    if (getcwd(actual_pwd, PATH_MAX) == NULL) {
        my_printe("getcwd() failed, please_retry\n");
        free(old_pwd);
        return -1;
    }
    shell->env = replace_venv(shell->env, "PWD", actual_pwd);
    shell->env = replace_venv(shell->env, "OLDPWD", old_pwd);
    free(actual_pwd);
    free(old_pwd);
    return 0;
}
