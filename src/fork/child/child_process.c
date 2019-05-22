/*
** EPITECH PROJECT, 2019
** 42SH
** File description:
** my_sh
*/

#include "shell.h"

int child_process(t_info *shell, t_command *command)
{
    char *path = search_env(shell->env, "PATH=");
    char **path_tab = my_str_to_word_array(path, ':');
    free(path);

    path = get_right_path(command->tab_command[0], path_tab);
    free_array(path_tab);
    if (path == NULL || check_path(path) == -1) {
        my_printe("%s: Command not found.\n", command->tab_command[0]);
    } else {
        execve(path, command->tab_command, shell->env);
        if (errno == 8) {
            my_printe("%s: %s. Wrong Architecture.\n", command->tab_command[0],
            strerror(errno));
        } else
            my_printe("%s: %s.\n", command->tab_command[0], strerror(errno));
    }
    delete_all(shell);
    exit(1);
}
