/*
** EPITECH PROJECT, 2019
** 42SH
** File description:
** repeat
*/

#include "shell.h"

long int error_my_repeat(t_command *command)
{
    long int nb_loop = -1;
    int len_tab = get_size_array(command->tab_command);
    char *endptr;

    if (len_tab < 3) {
        my_printe("repeat: Too few arguments.\n");
        return (RETURN_FAILURE);
    }
    nb_loop = strtol(command->tab_command[1], &endptr, 10);
    if (endptr[0] != '\0') {
        my_printe("repeat: Badly formed number.\n");
        return (RETURN_FAILURE);
    }
    return (nb_loop);
}

t_command *create_command_loop(t_command *command)
{
    t_command *cmd_loop = NULL;
    int len = get_size_array(command->tab_command);

    if ((cmd_loop = calloc(1, sizeof(t_command))) == NULL) {
        my_printe("Error: calloc() failed\n");
        return (NULL);
    }
    if ((cmd_loop->tab_command = calloc(len - 1, sizeof(char *))) == NULL) {
        my_printe("Error: calloc() failed\n");
        delete_command(cmd_loop);
        return (NULL);
    }
    for (int i = 2; command->tab_command[i]; i++)
        cmd_loop->tab_command[i - 2] = strdup(command->tab_command[i]);
    return (cmd_loop);
}

int my_repeat(t_info *shell, t_command *command)
{
    long int nb_loop = 0;
    t_command *command_loop = NULL;

    if ((nb_loop = error_my_repeat(command)) == RETURN_FAILURE)
        return (RETURN_FAILURE);
    if ((command_loop = create_command_loop(command)) == NULL)
        return (RETURN_FAILURE);
    for (int i = 0; i < nb_loop; i++) {
        if (do_execve(shell, command_loop) == RETURN_FAILURE) {
            delete_command(command_loop);
            return (RETURN_FAILURE);
        }
    }
    delete_command(command_loop);
    return (RETURN_SUCCESS);
}
