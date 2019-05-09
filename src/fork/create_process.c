/*
** EPITECH PROJECT, 2019
** 42SH
** File description:
** my_sh
*/

#include "shell.h"

pid_t create_process(void)
{
    pid_t pid = fork();
    while ((pid == -1) && (errno == EAGAIN)) {
        pid = fork();
    }
    return pid;
}