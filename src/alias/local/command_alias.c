/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** alias
*/

#include "shell.h"

char **new_line_command(int i, aliase_t *alias, char **tab_command)
{
    for (; alias->prev; alias = alias->prev);
    for (; alias->next; alias = alias->next) {
        if (my_strcmp(alias->new_name, tab_command[i]) == 0) {
            tab_command = replace_with_alias(alias, tab_command, i);
            return tab_command;
        }
    }
    if (my_strcmp(alias->new_name, tab_command[i]) == 0) {
        tab_command = replace_with_alias(alias, tab_command, i);
        return tab_command;
    }
    return tab_command;
}

char *init_new_command(char **tab_command)
{
    char *new_command = NULL;
    int count_malloc = 0;
    int k = 0;
    int i = 2;

    for (; tab_command[i]; i++)
        for (int j = 0; tab_command[i][j]; j++)
            count_malloc++;
    if ((new_command = malloc(sizeof(char) * (count_malloc + i + 1))) == NULL)
        return NULL;
    for (i = 2; tab_command[i]; i++) {
        for (int j = 0; tab_command[i][j]; j++, k++)
            new_command[k] = tab_command[i][j];
        new_command[k] = ' ';
        k++;
    }
    new_command[k - 1] = '\0';
    return new_command;
}

bool bad_new_alias_line(char **tab_command)
{
    if (my_strcmp(tab_command[0], "alias") != 0)
        return true;
    if (my_arraylen(tab_command) != 1)
        return true;
    return false;
}

aliase_t *local_alias(t_command *command, t_info *shell, bool *change)
{
    char *new_command = NULL;

    if (bad_new_alias_line(command->tab_command) == false) {
        (*change) = true;
        display_alias(shell->aliases);
        return shell->aliases;
    }
    if (show_one_alias(command->tab_command, shell) == true) {
        (*change) = true;
        return shell->aliases;
    }
    if (bad_alias_line(shell->command_line) == false) {
        (*change) = true;
        if ((new_command = init_new_command(command->tab_command)) == NULL)
            exit(84);
        if ((shell->aliases = add_alias_in_list(command->tab_command[1], \
new_command, shell->aliases)) == NULL)
            exit(84);
    }
    free(new_command);
    return shell->aliases;
}
