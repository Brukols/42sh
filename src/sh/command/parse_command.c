/*
** EPITECH PROJECT, 2019
** 42SH
** File description:
** parse_command
*/

#include "shell.h"

void display_aliase(aliase_t *alias)
{
    for (; alias->prev != NULL; alias = alias->prev);
    for (; alias != NULL; alias = alias->next) {
        printf("%s %s\n", alias->new_name, alias->command);
    }
}

t_command *_42sh_alias(t_command *command, t_info *shell)
{
    FILE *file = NULL;

    if ((file = _42rc_is_filled()) == NULL)
        return command;
    if ((shell->aliases = fill_42rc_since_file(shell->aliases, file)) == NULL)
        return NULL;
    display_aliase(shell->aliases);
    return command;
}

int parse_command(t_command *command, t_info *shell)
{
    int verif;

    if (command->tab_command[0] == NULL)
        return (RETURN_SUCCESS);
    if (my_strcmp(command->tab_command[0], "exit") == 0
    && my_strlen(command->tab_command[0]) == 4) {
        shell->exit = 1;
        return (RETURN_SUCCESS);
    }
    if ((command = _42sh_alias(command, shell)) == NULL)
        return EXIT_ERROR;
    command->tab_command = apply_globbings(command->tab_command);
    if (command->tab_command == NULL)
        return (EXIT_ERROR);
    if ((verif = local_and_env_variable(command, shell)) != VARIABLE)
        return (verif);
    if (is_skip_command(command))
        return (RETURN_SUCCESS);
    if (command_exec(command, shell) == RETURN_FAILURE)
        return (RETURN_FAILURE);
    return (RETURN_SUCCESS);
}
