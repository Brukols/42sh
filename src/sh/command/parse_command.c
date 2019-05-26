/*
** EPITECH PROJECT, 2019
** 42SH
** File description:
** parse_command
*/

#include "shell.h"

int options_command(t_command *command, t_info *shell)
{
    bool alias = false;

    command->tab_command = apply_globbings(command->tab_command);
    if (command->tab_command == NULL)
        return EXIT_ERROR;
    if ((shell->aliases = local_alias(command, shell, &alias)) == NULL)
        return EXIT_ERROR;
    if ((shell->aliases = unalias(command, shell, &alias)) == NULL)
        return EXIT_ERROR;
    if (alias == true)
        return RETURN_SUCCESS;
    if ((command = change_command_line(shell, command)) == NULL)
        return EXIT_ERROR;
    if ((command = global_alias(command, shell)) == NULL)
        return EXIT_ERROR;
    return 42;
}

int parse_command(t_command *command, t_info *shell)
{
    int verif;
    int options = 0;

    if (command->tab_command[0] == NULL)
        return (RETURN_SUCCESS);
    if ((options = options_command(command, shell)) == EXIT_ERROR)
        return EXIT_ERROR;
    if (options == RETURN_SUCCESS)
        return RETURN_SUCCESS;
    if ((verif = local_and_env_variable(command, shell)) != VARIABLE)
        return (verif);
    if (is_skip_command(command))
        return (RETURN_SUCCESS);
    if (command_exec(command, shell) == RETURN_FAILURE)
        return (RETURN_FAILURE);
    return (RETURN_SUCCESS);
}
