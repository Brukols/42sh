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

    if (array_alias == NULL)
        exit(84);
    if (my_arraylen(array_alias) < 3)
        return true;
    if (my_strcmp(array_alias[0], "alias") != 0 && \
        my_strcmp(array_alias[0], "lias") != 0)
        return true;
    free_array(array_alias);
    return false;
}

aliase_t *fill_42rc_since_file(aliase_t *alias, FILE *file)
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

FILE *_42rc_is_filled(void)
{
    FILE *stream = NULL;
    int first_char = 0;
    int fd = 0;

    if ((fd = open(".42rc", O_RDONLY | O_APPEND | O_CREAT, S_IRWXU \
| S_IRWXG | S_IRWXO)) == -1)
        exit(84);
    stream = fdopen(fd, "r");
    if (stream == NULL)
        exit(84);
    first_char = fgetc(stream);
    if (first_char == EOF) {
        close(fd);
        return NULL;
    }
    close(fd);
    return stream;
}
