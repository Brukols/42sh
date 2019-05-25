/*
** EPITECH PROJECT, 2019
** 42SH
** File description:
** delete_bg_process
*/

#include "shell.h"

pid_t *delete_process(pid_t *pids, int pos)
{
    int a = 0;
    int i = 0;
    pid_t *tmp = malloc(sizeof(pid_t) * (len_bg_process(pids)));

    if (!tmp)
        return (NULL);
    for (; pids[i] != -1; i++)
        tmp[i] = pids[i];
    tmp[i] = -1;
    free(pids);
    if (!(pids = malloc(sizeof(pid_t) * (len_bg_process(pids)))))
        return (NULL);
    for (i = 0; tmp[i] != -1; i++) {
        if (i == pos)
            continue;
        pids[a] = tmp[i];
        a++;
    }
    pids[a] = -1;
    free(tmp);
    return (pids);
}

pid_t *delete_bg_process(pid_t *all_bg_process, pid_t process)
{
    int i = 0;

    if (!all_bg_process)
        return (NULL);
    for (; all_bg_process[i] != -1 && all_bg_process[i] != process; i++);
    if (all_bg_process[i] == -1)
        return (all_bg_process);
    all_bg_process = delete_process(all_bg_process, i);
    return (all_bg_process);
}