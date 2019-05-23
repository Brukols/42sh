/*
** EPITECH PROJECT, 2019
** 42SH
** File description:
** init_builtin
*/

#include "shell.h"

t_builtin **init_builtin(void)
{
    t_builtin **builtin = malloc(sizeof(t_builtin *) * (7 + 1));
    if (builtin == NULL)
        return (NULL);
    int (*ft[7])(t_info*, t_command*) =
    {&my_cd, &my_setenv, &my_unsetenv, &my_env, &my_set, &my_unset, &history};
    char *name[] = {"cd", "setenv", "unsetenv", "env", "set", "unset",
        "history"};
    for (int i = 0; i < 7; i++) {
        builtin[i] = malloc(sizeof(t_builtin));
        if (builtin[i] == NULL)
            return (NULL);
        builtin[i]->name = my_strdup(name[i]);
        if (builtin[i]->name == NULL) {
            delete_builtin(builtin);
            return (NULL);
        }
        builtin[i]->ft = ft[i];
    }
    builtin[7] = NULL;
    return (builtin);
}
