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

int history(t_info *shell, t_command *command)
{
    char *buffer = NULL;
    char **array;

    if (get_size_array(command->tab_command) != 1)
        return (RETURN_FAILURE);
    lseek(shell->history, 0, SEEK_SET);
    while ((buffer = get_next_line(shell->history)) != NULL) {
        if ((array = my_str_to_word_array(buffer, '-')) == NULL)
            return (RETURN_FAILURE);
        my_printf("\t%s\t%s\t%s", array[0], array[1], array[2]);
        print_end_array(array);
        my_printf("\n");
        free_array(array);
        free(buffer);
    }
    return (RETURN_SUCCESS);
}