/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** init_history
*/

#include "shell.h"

int init_history(void)
{
    int fd = open(".history_42sh", O_RDWR | O_CREAT);

    return (fd);
}
