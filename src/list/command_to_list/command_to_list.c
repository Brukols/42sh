/*
** EPITECH PROJECT, 2019
** 42SH
** File description:
** command_to_list
*/

#include "shell.h"

void manage_quotation_command_list(char *str, int *i, int *len_word)
{
    char quote = 0;

    errno = 0;
    if (*i > 0 && str[*i - 1] == '\\')
        return;
    if (str[*i] != '"' && str[*i] != '\'')
        return;
    quote = str[*i];
    (*i)++;
    (*len_word)++;
    for (; str[*i] && str[*i] != quote; (*i)++, (*len_word)++);
    if (!str[*i]) {
        my_printf("Unmatched '%c'.\n", quote);
        errno = UNMATCHED_QUOTE;
        *i -= 1;
        (*len_word)--;
    }
}

t_list *command_to_list(char *str, char *sep)
{
    int len_word = 0;
    t_list *list = NULL;
    if ((list = create_list()) == NULL)
        return (NULL);
    for (int i = 0; str[i] != '\0'; i++) {
        manage_quotation_command_list(str, &i, &len_word);
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
