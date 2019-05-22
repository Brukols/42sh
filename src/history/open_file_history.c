/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** open_file_history
*/

#include "shell.h"

int open_file_history(void)
{
    char *buffer = recup_path_history();
    int fd;

    if (buffer == NULL)
        return (-1);
    fd = open(buffer, O_RDWR | O_APPEND | O_CREAT, S_IRUSR |
    S_IWUSR | S_IRGRP | S_IWGRP | S_IWOTH | S_IROTH);
    free(buffer);
    return (fd);
}