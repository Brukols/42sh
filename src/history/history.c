/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** history
*/

#include "shell.h"

char *recup_end_command(char *command)
{
    int i = 0;
    int nb = 0;
    char *tmp;
    int j = 0;

    for (; nb < 2; i++) {
        if (command[i] == '-')
            nb++;
    }
    if ((tmp = malloc(sizeof(char) * (strlen(command) - i + 1))) == NULL)
        return (NULL);
    for (;command[i] != '\0'; i++) {
        tmp[j] = command[i];
        j++;
    }
    tmp[j - 1] = '\0';
    return (tmp);
}

int loop_print_history(FILE *stream)
{
    size_t len = 0;
    int rd = 0;
    char *buffer = NULL;
    char **array;
    char *end;

    while ((rd = getline(&buffer, &len, stream)) != -1) {
        buffer[rd] = '\0';
        if ((end = recup_end_command(buffer)) == NULL) return (RETURN_FAILURE);
        if ((array = my_str_to_word_array(buffer, '-')) == NULL) {
            free(end);
            free(buffer);
            fclose(stream);
            return (RETURN_FAILURE);
        }
        my_printf("\t%s\t%s\t%s\n", array[0], array[1], end);
        free(end);
        free_array(array);
    }
    free(buffer);
    return (RETURN_SUCCESS);
}

int history(t_info *shell, t_command *command)
{
    FILE *stream;
    char *path;
    (void)shell;

    if (get_size_array(command->tab_command) != 1)
        return (RETURN_FAILURE);
    if ((path = recup_path_history()) == NULL)
        return (RETURN_FAILURE);
    if ((stream = fopen(path, "r")) == NULL) {
        free(path);
        return (RETURN_FAILURE);
    }
    free(path);
    if (loop_print_history(stream) == RETURN_FAILURE)
        return (RETURN_FAILURE);
    fclose(stream);
    return (RETURN_SUCCESS);
}
