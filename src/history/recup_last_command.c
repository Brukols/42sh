/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** recup_last_command
*/

#include "shell.h"

int find_last_command(FILE *stream)
{
    char *buffer = NULL;
    size_t len = 0;
    int nb = 0;

    while (getline(&buffer, &len, stream) != -1)
        nb++;
    free(buffer);
    fseek(stream, 0, SEEK_SET);
    return (nb);
}

char *get_line_history(int pos, FILE *stream)
{
    char *buffer = NULL;
    size_t len;
    char *line;

    for (int nb = 0; nb <= pos; nb++) {
        getline(&buffer, &len, stream);
    }
    if ((line = strdup(buffer)) == NULL) {
        free(buffer);
        return (NULL);
    }
    free(buffer);
    return (line);
}

char *transform_command(char *last_command)
{
    int nb = 0;
    int i = 0;
    int j = 0;
    char *command;

    for (i = 0; nb != 2; i++) {
        if (last_command[i] == '-')
            nb++;
    }
    command = malloc(sizeof(char) * (strlen(last_command) - i + 1));
    if (command == NULL)
        return (NULL);
    for (i = i; last_command[i] != '\0'; i++) {
        command[j] = last_command[i];
        j++;
    }
    command[j - 1] = '\0';
    free(last_command);
    return (command);
}

char *recup_last_command(void)
{
    char *path = recup_path_history();
    FILE *stream;
    int pos;
    char *last_command;

    if (path == NULL)
        return (NULL);
    if ((stream = fopen(path, "r")) == NULL)
        return (NULL);
    free(path);
    pos = find_last_command(stream);
    if ((last_command = get_line_history(pos, stream)) == NULL)
        return (NULL);
    if ((last_command = transform_command(last_command)) == NULL)
        return (NULL);
    fclose(stream);
    return (last_command);
}