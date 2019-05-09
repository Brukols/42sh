/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** my_str_to_word_array
*/

#include "my.h"

int check_alphanumeric(char c, char sep)
{
    if (c != sep && c != '\n' && c != '\0' && c != '\t') {
        return 1;
    } else {
        return 0;
    }
}

int count_word(char *str, char sep)
{
    int word_number = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (check_alphanumeric(str[i], sep)
        && !check_alphanumeric(str[i + 1], sep)) {
            word_number++;
        }
    }
    return word_number;
}

char **my_str_to_word_array(char *str, char sep)
{
    int index = 0;
    int len_word = 0;
    char **tab_result = malloc(sizeof(char *) * (count_word(str, sep) + 1));
    if (tab_result == NULL)
        return (NULL);
    for (int i = 0; str[i] != '\0'; i++) {
        if (check_alphanumeric(str[i], sep))
            len_word++;
        if (check_alphanumeric(str[i], sep)
        && !check_alphanumeric(str[i + 1], sep)) {
            tab_result[index] = malloc(len_word + 1);
            if (tab_result[index] == NULL)
                return NULL;
            my_strncpy(tab_result[index], &str[i - len_word + 1], len_word);
            len_word = 0;
            index++;
        }
    }
    tab_result[index] = NULL;
    return tab_result;
}
