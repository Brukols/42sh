/*
** EPITECH PROJECT, 2019
** 42SH
** File description:
** delete_quote_set
*/

#include "shell.h"

char *delete_one_chara(char *str, int pos)
{
    int i = 0;
    int a = 0;
    char *new = malloc(sizeof(char) * (my_strlen(str) + 1));

    if (!new)
        return (NULL);
    for (; str[i]; i++) {
        if (i == pos)
            continue;
        new[a] = str[i];
        a++;
    }
    new[a] = '\0';
    free(str);
    return (new);
}

int check_quote_matched(char *parse, int *n, char *str)
{
    for (; str[*n] && str[*n] != *parse; (*n)++);
    if (!str[*n]) {
        my_printf("Unmatched '%c'.\n", *parse);
        return (UNMATCHED_QUOTE);
    }
    return (EXIT_SUCCESS);
}

int re_init_tab_command(t_command *cmd, int n, int i, char **str)
{
    cmd->tab_command[i] = delete_one_chara(cmd->tab_command[i], n);
    if (!cmd->tab_command[i])
        return (EXIT_FAILURE);
    (*str) = cmd->tab_command[i];
    return (EXIT_SUCCESS);
}

int do_the_delete(t_command *cmd, int i, char *str, int n)
{
    int verif = 0;
    char parse = 0;

    for (n++; str[n]; n++) {
        if (parse == 0 && (str[n] == '"' || str[n] == '\'')) {
            parse = str[n];
            verif = re_init_tab_command(cmd, n, i, &str);
        }
        if (verif == EXIT_FAILURE)
            return (EXIT_FAILURE);
        if (parse == 0)
            continue;
        if (check_quote_matched(&parse, &n, str) == UNMATCHED_QUOTE)
            return (UNMATCHED_QUOTE);
        if (re_init_tab_command(cmd, n, i, &str) == EXIT_FAILURE)
            return (EXIT_FAILURE);
        n--;
    }
    return (EXIT_SUCCESS);
}

int delete_quotation_set(t_command *cmd, int i)
{
    int n = 0;
    char *str = cmd->tab_command[i];

    for (; str[n] && str[n] != '='; n++);
    if (!str[n] || !str[n + 1])
        return (EXIT_SUCCESS);
    return (do_the_delete(cmd, i, str, n));
}