/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** alias
*/

#include "shell.h"

char *split_alias_name(char *all, int *i)
{
    char *tmp = NULL;
    int save = 0;

    for (; all[save] != ' '; save++);
    save++;
    (*i) = save;
    for (; all[save] != ' '; save++);
    if ((tmp = malloc(sizeof(char) * (save + 1))) == NULL)
        return NULL;
    for (save = 0; all[(*i)] != ' '; save++, (*i)++)
        tmp[save] = all[(*i)];
    tmp[save] = '\0';
    return tmp;
}

char *split_alias_value(char *all, int i)
{
    char *tmp = NULL;
    int save = i + 1;

    for (; all[i] != '\0'; ++i);
    if ((tmp = malloc(sizeof(char) * (i + 1))) == NULL)
        return NULL;
    for (i = 0; all[save] != '\0'; save++, i++)
        tmp[i] = all[save];
    tmp[i] = '\0';
    return tmp;
}
