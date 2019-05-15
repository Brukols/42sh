/*
** EPITECH PROJECT, 2019
** 42SH
** File description:
** delete_all_quotation_set
*/

#include "shell.h"

int delete_all_quotation_set(t_command *cmd)
{
    int verif;

    for (int i = 1; cmd->tab_command[i]; i++) {
        if ((verif = delete_quotation_set(cmd, i)) == UNMATCHED_QUOTE)
            return (UNMATCHED_QUOTE);
        if (verif == EXIT_FAILURE)
            return (EXIT_FAILURE);
    }
    return (EXIT_SUCCESS);
}