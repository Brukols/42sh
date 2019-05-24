/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** add_in_history
*/

#include "shell.h"

char *find_nb_command_line(void)
{
    int nb = 1;
    char *buffer = NULL;
    FILE *stream;
    size_t len = 0;
    char *path = recup_path_history();
    char *nb_final;

    if (path == NULL)
        return NULL;
    if ((stream = fopen(path, "r")) == NULL)
        return NULL;
    while (getline(&buffer, &len, stream) != -1)
        nb++;
    free(buffer);
    if ((nb_final = my_itoa(nb)) == NULL)
        return (NULL);
    free(path);
    fclose(stream);
    return (nb_final);
}

char *find_time_command_line(void)
{
    time_t timep = time(NULL);
    struct tm *tm = localtime(&timep);
    char *hour = my_itoa(tm->tm_hour);
    char *min = my_itoa(tm->tm_min);
    int len = 0;
    char *buffer;
    char *double_dot = ":";

    if (hour == NULL || min == NULL)
        return (NULL);
    len = my_strlen(hour) + my_strlen(min) + 1;
    if ((buffer = malloc(sizeof(char) * (len + 1))) == NULL)
        return (NULL);
    buffer[0] = '\0';
    buffer = strcat(buffer, hour);
    buffer = strcat(buffer, double_dot);
    buffer = strcat(buffer, min);
    free(hour);
    free(min);
    return (buffer);
}

int add_in_history(char *command_line)
{
    int fd = open_file_history();
    char *nb_command;
    char *time = find_time_command_line();
    if (fd == -1)
        return (-1);
    if (command_line == NULL || command_line[0] == '\0' ||
    command_line[0] == '\n') {
        free(time);
        close(fd);
        return (-1);
    }
    if ((nb_command = find_nb_command_line()) == NULL) {
        close(fd);
        return (-1);
    }
    dprintf(fd, "%s-%s-%s\n", nb_command, time, command_line);
    free(nb_command);
    free(time);
    close(fd);
    return (0);
}
