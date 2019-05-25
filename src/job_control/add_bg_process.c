/*
** EPITECH PROJECT, 2019
** add_bg_process.c
** File description:
** 42SH
*/

#include "shell.h"

pid_t *realloc_bg_process(pid_t *all_bg_process)
{
    int i = 0;
    pid_t *tmp = malloc(sizeof(pid_t) * (len_bg_process(all_bg_process)));

    if (!tmp)
        return (NULL);
    for (; all_bg_process[i] != -1; i++)
        tmp[i] = all_bg_process[i];
    tmp[i] = -1;
    free(all_bg_process);
    all_bg_process = malloc(sizeof(int) * (len_bg_process(tmp) + 1));
    if (!all_bg_process)
        return (NULL);
    for (i = 0; tmp[i]; i++)
        all_bg_process[i] = tmp[i];
    all_bg_process[i] = -1;
    free(tmp);
    return (all_bg_process);
}

pid_t *add_bg_process(pid_t *all_bg_process, pid_t process)
{
    int i = 0;

    if (!all_bg_process) {
        all_bg_process = malloc(sizeof(int) * 2);
        if (!all_bg_process)
            return (NULL);
        all_bg_process[0] = process;
        all_bg_process[1] = -1;
    } else {
        all_bg_process = realloc_bg_process(all_bg_process);
        if (!all_bg_process)
            return (NULL);
        for (; all_bg_process[i] != -1; i++);
        all_bg_process[i + 1] = -1;
        all_bg_process[i] = process;
    }
    return (all_bg_process);
}