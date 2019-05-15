/*
** EPITECH PROJECT, 2019
** 42SH
** File description:
** command_to_list_double_sep
*/

#include "shell.h"

t_list *command_to_list_double_sep(char *str, char *sep)
{
    int len_word = 0;
    t_list *list = NULL;
    if ((list = create_list()) == NULL)
        return (NULL);
    for (int i = 0; str[i] != '\0'; i++) {
        if (!check_sep_double(str[i], str[i + 1], sep))
            len_word++;
        if (!check_sep_double(str[i], str[i + 1], sep)
        && check_sep_double(str[i + 1], str[i + 2], sep)) {
            t_command *command = create_command(len_word, str, i);
            if (command == NULL)
                return (NULL);
            if ((command = get_separator_double(command, str, sep, i)) == NULL)
                return (NULL);
            list = add_to_list(list, command);
            len_word = 0;
            i += 2;
        }
    }
    return (list);
}
