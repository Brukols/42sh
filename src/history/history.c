/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** history
*/

#include "shell.h"

int history(t_info *shell, t_command *command)
{
    char *buffer = NULL;
    char **array;

    if (get_size_array(command->tab_command) != 1)
        return (RETURN_FAILURE);
    lseek(shell->history, 0, SEEK_SET);
    while ((buffer = get_next_line(shell->history)) == NULL) {
        if ((array = my_str_to_word_array(buffer, '-')) == NULL)
            return (RETURN_FAILURE);
        my_printf("\t%s\t%s\t%s\n", array[0], array[1], array[2]);
        free_array(array);
        free(buffer);
    }
    return (RETURN_SUCCESS);
}