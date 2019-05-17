/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** globbings
*/

#include "shell.h"

char **apply_globbings(char **tab_command)
{
    glob_t globbuf;
    char **tmp = NULL;
    int i = 0;

    globbuf.gl_offs = 0;
    while (tab_command[i]) {
        glob(tab_command[i], (i == 0 ? GLOB_DOOFFS | GLOB_NOCHECK : \
GLOB_DOOFFS | GLOB_APPEND | GLOB_NOCHECK), NULL, &globbuf);
        i++;
    }
    if ((tmp = malloc(sizeof(char *) * \
(get_size_array(globbuf.gl_pathv) + 1))) == NULL)
        return NULL;
    i = 0;
    while (globbuf.gl_pathv[i]) {
        if ((tmp[i] = my_strdup(globbuf.gl_pathv[i])) == NULL)
            return NULL;
        i++;
    }
    tmp[i] = NULL;
    globfree(&globbuf);
    return tmp;
}
