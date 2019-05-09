/*
** EPITECH PROJECT, 2019
** 42SH
** File description:
** create_venv
*/

#include "shell.h"

void create_venv(char *new_v, char *name, char *value)
{
    my_strcpy(new_v, name);
    my_strcat(new_v, "=");
    if (value != NULL)
        my_strcat(new_v, value);
}
