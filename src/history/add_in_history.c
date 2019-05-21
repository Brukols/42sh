/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** add_in_history
*/

#include "shell.h"

char *find_nb_command_line(int fd)
{
    int nb = 0;
    char *buffer = NULL;

    if (lseek(fd, 0, SEEK_SET) == -1)
        return (NULL);
    while (get_next_line(fd) != NULL)
        nb++;
    buffer = my_itoa(nb);
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
    my_printf("%s", buffer);
    return (buffer);
}

int add_in_history(char *command_line, int fd)
{
    char *nb_command = find_nb_command_line(fd);
    char *time = find_time_command_line();

    if (nb_command == NULL)
        return (-1);
    write(fd, nb_command, strlen(nb_command));
    write(fd, "-", 1);
    write(fd, time, strlen(time));
    write(fd, "-", 1);
    if (lseek(fd, 0, SEEK_END) == -1)
        return (-1);
    write(fd, command_line, strlen(command_line));
    write(fd, "\n"  , 1);
    return (0);
}
