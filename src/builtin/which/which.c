/*
** EPITECH PROJECT, 2019
** 42SH
** File description:
** which
*/

#include "shell.h"

int error_which(t_command *command)
{
    if (get_size_array(command->tab_command) < 2) {
        my_printe("which: Too few arguments.\n");
        return (RETURN_FAILURE);
    }
    return (RETURN_SUCCESS);
}

int my_which(t_info *shell, t_command *command)
{
    char *path = NULL;
    char **path_tab = NULL;
    if (error_which(command) == RETURN_FAILURE) return (RETURN_FAILURE);
    path = search_env(shell->env, "PATH=");
    path_tab = my_str_to_word_array(path, ':');
    free(path);
    for (int i = 1; command->tab_command[i]; i++) {
        if (is_builtin(command->tab_command[i], shell->builtin) != -1) {
            my_printf("%s: shell built-in command.\n", command->tab_command[i]);
            continue;
        }
        path = get_right_path(command->tab_command[i], path_tab);
        if (path == NULL || check_path(path) == -1)
            my_printe("%s: Command not found.\n", command->tab_command[i]);
        else
            my_printf("%s\n", path);
        free(path);
    }
    free_array(path_tab);
    return (RETURN_SUCCESS);
}
