/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** alias
*/

#include "shell.h"

char **remplace_with_alias(aliase_t *alias, char **tab_command, int i)
{
    char **alias_command = my_str_to_word_array(alias->command, ' ');
    char **tmp = malloc(sizeof(char *) * (my_arraylen(tab_command)      \
+ my_arraylen(alias_command) + 1));
    int pos = 0;
    int j = 0;
    int k = 0;

    if (tmp == NULL || alias_command == NULL)
        exit(84);
    for (; pos < i; pos++)
        if ((tmp[pos] = my_strdup(tab_command[pos])) == NULL)
            exit(84);
    for (j = pos, k = 0; alias_command[k]; ++j, k++)
        if ((tmp[j] = my_strdup(alias_command[k])) == NULL)
            exit(84);
    for (i = i + 1; tab_command[i]; i++, ++j)
        if ((tmp[j] = my_strdup(tab_command[i])) == NULL)
            exit(84);
    tmp[j] = NULL;
    free_array(alias_command);
    return tmp;
}

char **new_line_command(int i, aliase_t *alias, char **tab_command)
{
    for (; alias->prev; alias = alias->prev);
    for (; alias->next; alias = alias->next) {
        if (my_strcmp(alias->new_name, tab_command[i]) == 0) {
            tab_command = remplace_with_alias(alias, tab_command, i);
            return tab_command;
        }
    }
    if (my_strcmp(alias->new_name, tab_command[i]) == 0) {
        tab_command = remplace_with_alias(alias, tab_command, i);
        return tab_command;
    }
    return tab_command;
}

t_command *change_command_line(t_info *shell, t_command *command)
{
    for (int i = 0; command->tab_command[i]; i++) {
        if ((command->tab_command = new_line_command(i, \
shell->aliases, command->tab_command)) == NULL)
            exit(84);
    }
    return command;
}
