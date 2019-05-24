/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** history
*/

#include "shell.h"

void print_end_array(char **array)
{
    for (int i = 3; array[i] != NULL; i++)
        my_printf("-%s", array[i]);
}

int loop_print_history(FILE *stream)
{
    size_t len = 0;
    int rd = 0;
    char *buffer = NULL;
    char **array;

    while ((rd = getline(&buffer, &len, stream)) != -1) {
        buffer[rd] = '\0';
        if ((array = my_str_to_word_array(buffer, '-')) == NULL) {
            free(buffer);
            fclose(stream);
            return (RETURN_FAILURE);
        }
        my_printf("\t%s\t%s\t%s", array[0], array[1], array[2]);
        print_end_array(array);
        my_printf("\n");
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