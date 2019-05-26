/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** alias
*/

#include "shell.h"

bool bad_alias_line(char *alias)
{
    char **array_alias = my_str_to_word_array(alias, ' ');

    if (array_alias == NULL) {
        free_array(array_alias);
        exit(84);
    }
    if (my_arraylen(array_alias) < 3) {
        free_array(array_alias);
        return true;
    }
    if (my_strcmp(array_alias[0], "alias") != 0
    && my_strcmp(array_alias[0], "lias") != 0) {
        free_array(array_alias);
        return true;
    }
    free_array(array_alias);
    return false;
}

aliase_t *fill_alias_since_file(aliase_t *alias, FILE *file)
{
    size_t len = 0;
    char *all_alias = NULL;
    char *value = NULL;
    char *name = NULL;

    for (int i = 0; getline(&all_alias, &len, file) != -1; i = 0) {
        if (bad_alias_line(all_alias) == true)
            continue;
        if ((name = split_alias_name(all_alias, &i)) ==  \
            NULL)
            return NULL;
        if ((value = split_alias_value(all_alias, i)) == \
            NULL)
            return NULL;
        if ((add_alias_in_list(name, value, alias)) == NULL)
            return NULL;
    }
    free(name);
    free(value);
    free(all_alias);
    return alias;
}
