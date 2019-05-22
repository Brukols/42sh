/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** create 42rc file
*/

#include "shell.h"

int create_42rc(t_info *shell)
{
    return 0;
    int fd = 0;
    FILE *file = 0;

    if ((fd = open(".42rc", O_WRONLY | O_APPEND | O_CREAT, S_IRUSR \
| S_IRGRP | S_IROTH)) == -1)
        return 84;
    if ((file = fdopen(fd, "w")) == NULL)
        return 84;
    shell->_42rc = file;
    return 0;
}
