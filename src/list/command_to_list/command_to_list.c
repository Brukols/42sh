/*
** EPITECH PROJECT, 2019
** 42SH
** File description:
** command_to_list
*/

#include "shell.h"

t_list *command_to_list(char *str, char *sep)
{
    int len_word = 0;
    t_list *list = NULL;
    if ((list = create_list()) == NULL)
        return (NULL);
    for (int i = 0; str[i] != '\0'; i++) {
        if (!check_sep(str[i], sep) || no_inhibitor(str, i) == true)
            len_word++;
        if ((!check_sep(str[i], sep) && check_sep(str[i + 1], sep) && \
str[i] != '\\') || !str[i + 1]) {
            t_command *command = create_command(len_word, str, i);
            if (command == NULL)
                return (NULL);
            if ((command = get_separator(command, str, sep, i)) == NULL)
                return (NULL);
            list = add_to_list(list, command);
            len_word = 0;
        }
    }
    return (list);
}
