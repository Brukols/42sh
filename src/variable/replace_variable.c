/*
** EPITECH PROJECT, 2019
** 42SH
** File description:
** replace variable
*/

#include "shell.h"

bool is_alphanumeric(char c)
{
    if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || \
(c >= 'A' && c <= 'Z') || c == '_')
        return (true);
    return (false);
}

char *get_name_variable(t_command *cmd, int i, int a)
{
    int n = 0;
    char *name = malloc(sizeof(char) * (my_strlen(cmd->tab_command[i]) + 1));

    if (!name)
        return (NULL);
    name[0] = '\0';
    a++;
    for (; is_alphanumeric(cmd->tab_command[i][a]); n++, a++)
        name[n] = cmd->tab_command[i][a];
    name[n] = '\0';
    return (name);
}

bool name_is_an_int(char *name)
{
    for (int i = 0; name[i]; i++) {
        if (name[i] < '0' || name[i] > '9')
            return (false);
    }
    return (true);
}

int variable_does_not_exist(char *name)
{
    if (name_is_an_int(name) == true) {
        free(name);
        return (EXIT_SUCCESS);
    }
    my_printf("%s: Undefined variable.\n", name);
    free(name);
    return (EXIT_SUCCESS);
}

int replace_variable(t_command *cmd, t_info *shell, int i, int a)
{
    int verif;
    char *name = get_name_variable(cmd, i, a);
    char **value;

    if (!name)
        return (EXIT_FAILURE);
    if (my_strlen(name) == 0) {
        free(name);
        return (VARIABLE);
    }
    if (!(value = get_value_name(shell, name)))
        return (variable_does_not_exist(name));
    verif = change_tab_command(cmd, value, i, a);
    free(name);
    return (verif);
}