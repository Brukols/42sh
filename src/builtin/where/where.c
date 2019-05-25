/*
** EPITECH PROJECT, 2019
** 42SH
** File description:
** which
*/

#include "shell.h"

int error_where(t_command *command)
{
    if (get_size_array(command->tab_command) < 2) {
        my_printe("where: Too few arguments.\n");
        return (RETURN_FAILURE);
    }
    return (RETURN_SUCCESS);
}

int search_where(t_command *command, char **path_tab,
char *right_path, t_builtin **builtin)
{
    for (int i = 1; command->tab_command[i]; i++) {
        if (is_builtin(command->tab_command[i], builtin) != -1)
            my_printf("%s is a shell built-in\n", command->tab_command[i]);
        if (already_path(command->tab_command[i])) {
            my_printe("where: / in command makes no sense\n");
            continue;
        }
        for (int j = 0; path_tab[j]; j++) {
            my_strncpy(right_path, path_tab[j], my_strlen(path_tab[j]));
            my_strcat(right_path, "/");
            my_strcat(right_path, command->tab_command[i]);
            if (check_path(right_path) != -1)
                my_printf("%s\n", right_path);
            memset(right_path, 0, PATH_MAX);
        }
    }
    return (RETURN_SUCCESS);
}

int my_where(t_info *shell, t_command *command)
{
    char *path = NULL;
    char **path_tab = NULL;
    char *right_path = NULL;

    if (error_where(command) == RETURN_FAILURE)
        return (RETURN_FAILURE);
    if ((right_path = calloc(PATH_MAX, sizeof(char))) == NULL)
        return (RETURN_FAILURE);
    path = search_env(shell->env, "PATH=");
    path_tab = my_str_to_word_array(path, ':');
    free(path);
    if (search_where(command, path_tab, right_path, shell->builtin)
    == RETURN_FAILURE) {
        free(right_path);
        free_array(path_tab);
        return (RETURN_FAILURE);
    }
    free(right_path);
    free_array(path_tab);
    return (RETURN_SUCCESS);
}
