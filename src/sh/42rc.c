/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** create 42rc file
*/

#include "shell.h"

bool command_is_ok(t_command *command, t_info *shell)
{
    int i = 0;

    while (command->tab_command[i]) {
        if (my_strcmp(command->tab_command[i], "alias") == 0)
            break;
        i++;
    }
    if (command->tab_command[i] == NULL)
        return false;
    if (command->tab_command[i + 1] == NULL)
        return false;
    if (command->tab_command[i + 2] == NULL)
        return false;
    shell->aliases->position = i;
    return true;
}

int alias_command(t_command *command, t_info *shell)
{
    int fd = 0;

    if ((fd = open(".42rc", O_RDONLY)) == -1)
        return 84;

    if (command_is_ok(command, shell) == false)
        return 0;
    return 0;
}
