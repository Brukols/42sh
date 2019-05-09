/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** get_next_line
*/

#include "my.h"

char *mem_line(char *line, char *buffer, int i, int j)
{
    char *newline = NULL;
    int len = 0;

    if (line != 0) {
        len = my_strlen(line);
        newline = malloc(sizeof(char) * (len + j + 1));
        if (newline == NULL)
            return NULL;
        my_strncpy(newline, line, len);
    } else {
        newline = malloc(sizeof(char) * (len + j + 1));
        if (newline == NULL)
            return NULL;
    }
    newline[len + j] = '\0';
    my_strncpy(newline + len, buffer + i, j);
    free(line);
    return (newline);
}

char *get_next_line(int fd)
{
    static char buffer[READ_SIZE];
    static int size = 1;
    static int i = 1;
    char *line = NULL;
    for (int j = 0, new = 1; new != 0; j++) {
        if (size <= i) {
            i = j = 0;
            new = size = read(fd, buffer, READ_SIZE);
            buffer[size] = '\0';
        }
        if (buffer[i + j] == '\n' && new > 0) {
            line = mem_line(line, buffer, i, j);
            i = i + j + 1;
            return line;
        } else if (buffer[i + j] == '\0' && new > 0) {
            line = mem_line(line, buffer, i, j + 1);
            i = size;
        }
    }
    return line;
}
