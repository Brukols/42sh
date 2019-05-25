/*
** EPITECH PROJECT, 2019
** 42SH
** File description:
** my_echo
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

int my_echo(__attribute__((unused)) t_info *shell, t_command *cmd)
{
    bool new_line = true;
    int i = 1;
    char quote = 0;

    if (cmd->tab_command[1] && strcmp(cmd->tab_command[1], "-n") == 0) {
        new_line = false;
        i++;
    }
    for (; cmd->tab_command[i]; i++) {
        for (int a = 0; cmd->tab_command[i][a]; a++)
            write_with_enable_true(&quote, &a, cmd->tab_command[i]);
        if (cmd->tab_command[i + 1])
            my_putchar(' ');
    }
    if (new_line == true)
        my_putchar('\n');
    return (RETURN_SUCCESS);
}