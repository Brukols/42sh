/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** alias
*/

#include "shell.h"

FILE *alias_is_filled(void)
{
    FILE *stream = NULL;
    int first_char = 0;
    int fd = 0;
    char *path = recup_path_alias();

    if (path == NULL) return NULL;
    if ((fd = open(path, O_RDONLY | O_APPEND | O_CREAT, S_IRWXU \
| S_IRWXG | S_IRWXO)) == -1) exit(84);
    stream = fdopen(fd, "r");
    if (stream == NULL) exit(84);
    first_char = fgetc(stream);
    if (first_char == EOF) {
        close(fd);
        fclose(stream);
        free(path);
        return NULL;
    }
    free(path);
    close(fd);
    return stream;
}
