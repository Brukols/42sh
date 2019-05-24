/*
** EPITECH PROJECT, 2019
** 42SH
** File description:
** init_builtin
*/

#include "shell.h"

t_builtin **init_builtin(void)
{
    t_builtin **builtin = malloc(sizeof(t_builtin *) * (9 + 1));
    if (builtin == NULL)
        return (NULL);
    int (*ft[9])(t_info*, t_command*) =
    {&my_cd, &my_setenv, &my_unsetenv, &my_env, &my_set, &my_unset, &history,
        &my_repeat, &my_which};
    char *name[] = {"cd", "setenv", "unsetenv", "env", "set", "unset",
        "history", "repeat", "which"};
    for (int i = 0; i < 9; i++) {
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
    builtin[9] = NULL;
    return (builtin);
}
