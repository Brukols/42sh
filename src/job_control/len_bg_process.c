/*
** EPITECH PROJECT, 2019
** 42SH
** File description:
** len_bg_process
*/

#include "shell.h"

int len_bg_process(pid_t *all_bg_process)
{
    int len = 0;

    for (; all_bg_process[len] != -1; len++);
    return (len + 1);
}