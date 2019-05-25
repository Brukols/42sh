/*
** EPITECH PROJECT, 2019
** 42SH
** File description:
** my_echo
*/

#include "shell.h"

bool good_flags(char *str)
{
    if (str[0] != '-')
        return (false);
    for (int i = 1; str[i]; i++) {
        if (str[i] != 'n' && str[i] != 'e' && str[i] != 'E')
            return (false);
    }
    return (true);
}

void change_flags(char *str, bool *new_line, bool *enable_bs)
{
    for (int i = 1; str[i]; i++) {
        if (str[i] == 'n')
            (*new_line) = false;
        if (str[i] == 'e')
            (*enable_bs) = true;
        if (str[i] == 'E')
            (*enable_bs) = false;
    }
}

void check_arg(char **cmd, bool *new_line, bool *enable_bs, int *i)
{
    for (; cmd[*i] && good_flags(cmd[*i]) == true; (*i)++)
        change_flags(cmd[*i], new_line, enable_bs);
}

void write_cmd(char *cmd, bool enable_bs, char *quote)
{
    int i = 0;

    for (; cmd[i]; i++) {
        if (enable_bs == true)
            write_with_enable_true(quote, &i, cmd);
        else
            write_with_enable_false(quote, cmd[i]);
    }
}

int my_echo(__attribute__((unused)) t_info *shell, t_command *cmd)
{
    bool new_line = true;
    bool enable_bs = false;
    int i = 1;
    char quote = 0;

    check_arg(cmd->tab_command, &new_line, &enable_bs, &i);
    for (; cmd->tab_command[i]; i++) {
        write_cmd(cmd->tab_command[i], enable_bs, &quote);
        if (cmd->tab_command[i])
            my_putchar(' ');
    }
    if (new_line == true)
        my_putchar('\n');
    return (RETURN_SUCCESS);
}