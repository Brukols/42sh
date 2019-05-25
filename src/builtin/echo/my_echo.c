/*
** EPITECH PROJECT, 2019
** 42SH
** File description:
** my_echo
*/

#include "shell.h"

bool write_special_chara_next(char *str, int *i)
{
    switch (str[*i]) {
    case 'n':
        my_putchar('\n');
        break;
    case 'r':
        my_putchar('\r');
        break;
    case 't':
        my_putchar('\t');
        break;
    case 'v':
        my_putchar('\v');
        break;
    default:
        *i -= 1;
        return (false);
    }
    return (true);
}

bool write_special_chara(char *str, int *i)
{
    switch (str[*i]) {
    case '\\':
        my_putchar('\\');
        break;
    case 'a':
        my_putchar('\a');
        break;
    case 'b':
        my_putchar('\b');
        break;
    case 'e':
        my_putchar('\e');
        break;
    case 'f':
        my_putchar('\f');
        break;
    default:
        return (write_special_chara_next(str, i));
    }
    return (true);
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
        *i += 1;
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