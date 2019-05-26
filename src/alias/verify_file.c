/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** alias
*/

#include "shell.h"

FILE *_42rc_is_filled(void)
{
    FILE *stream = NULL;
    int first_char = 0;
    int fd = 0;

    if ((fd = open(".alias", O_RDONLY | O_APPEND | O_CREAT, S_IRWXU \
| S_IRWXG | S_IRWXO)) == -1)
        exit(84);
    stream = fdopen(fd, "r");
    if (stream == NULL)
        exit(84);
    first_char = fgetc(stream);
    if (first_char == EOF) {
        close(fd);
        fclose(stream);
        return NULL;
    }
    close(fd);
    return stream;
}
