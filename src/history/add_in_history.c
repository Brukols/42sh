/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** add_in_history
*/

#include "shell.h"

char *find_nb_command_line(int fd)
{
    int nb = 1;
    char *buffer = NULL;
    FILE *stream = fopen(".history_42sh", "r");
    size_t len;

    if (stream == NULL)
        return NULL;
    while (getline(&buffer, &len, stream) != -1)
        nb++;
    buffer = my_itoa(nb);
    fclose(stream);
    return (buffer);
}

char *find_time_command_line(void)
{
    time_t timep= time(NULL);
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
    return (buffer);
}

int add_in_history(char *command_line)
{
    int fd = open_file_history();
    char *nb_command;
    char *time = find_time_command_line();

    if (fd == -1)
        return (-1);
    if ((nb_command = find_nb_command_line(fd)) == NULL) {
        close(fd);
        return (-1);
    }
    lseek(fd, 0, SEEK_END);
    write(fd, nb_command, strlen(nb_command));
    write(fd, "-", 1);
    write(fd, time, strlen(time));
    write(fd, "-", 1);
    write(fd, command_line, strlen(command_line));
    write(fd, "\n"  , 1);
    free(nb_command);
    free(time);
    close(fd);
    return (0);
}
