/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** open_file_history
*/

#include "shell.h"

int open_file_history(void)
{
    int fd = open(".history_42sh", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR |
    S_IRGRP | S_IWGRP | S_IWOTH | S_IROTH);

    return (fd);
}