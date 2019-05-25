/*
** EPITECH PROJECT, 2019
** write_echo
** File description:
** 42SH
*/

#include "shell.h"

bool write_special_chara(char *str, int *i)
{
    char value[3];
    char *all_value = "\\abcefnrtv";

    (*i)++;
    value[0] = '\\';
    value[2] = '\0';
    for (int a = 0; all_value[a]; a++) {
        if (all_value[a] == str[*i]) {
            value[1] = all_value[a];
            my_putstr(value);
            return (true);
        }
    }
    (*i)--;
    return (false);
}

void write_with_enable_true(char *quote, int *i, char *str)
{
    if ((*quote) == 0 && (str[*i] == '"' || str[*i] == '\'')) {
        (*quote) = str[*i];
        return;
    }
    if (str[*i] == (*quote)) {
        (*quote) = 0;
        return;
    }
    if (str[*i] == '\\') {
        if (write_special_chara(str, i) == true)
            return;
    }
    my_putchar(str[*i]);
}

void write_with_enable_false(char *quote, char c)
{
    if ((*quote) == 0 && (c == '"' || c == '\'')) {
        (*quote) = c;
        return;
    }
    if (c == (*quote)) {
        (*quote) = 0;
        return;
    }
    my_putchar(c);
}