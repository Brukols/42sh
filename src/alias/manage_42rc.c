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
    if (my_strcmp(array_alias[0], "alias") != 0)
        return true;
    free_array(array_alias);
    return false;
}

int split_alias_name_and_value(char *full_alias, \
char separator, aliase_t *alias, int *i)
{
    char *tmp = NULL;

    for (; full_alias[(*i)] != separator; (*i)++);
    if ((tmp = malloc(sizeof(char) * ((*i) + 1))) == NULL)
        return RETURN_FAILURE;
    for ((*i) = 0; full_alias[(*i)] != separator; (*i)++)
        tmp[(*i)] = full_alias[(*i)];
    tmp[(*i)] = '\0';
    if (separator == ' ')
        if ((alias->new_name = my_strdup(tmp)) == NULL)
            return RETURN_FAILURE;
    if (separator == ' ')
        if ((alias->new_name = my_strdup(tmp)) == NULL)
            return RETURN_FAILURE;
    return SUCCESS;
}

aliase_t *fill_42rc_since_file(aliase_t *alias, FILE *file)
{
    size_t len = 0;
    char *all_alias = NULL;

    for (int i = 0; getline(&all_alias, &len, file) != -1; i = 0) {
        if (bad_alias_line(all_alias) == true)
            continue;
        if (split_alias_name_and_value(all_alias, ' ', alias, &i) == RETURN_FAILURE)
            return NULL;
        i++;
        if (split_alias_name_and_value(all_alias, '\0', alias, &i) == RETURN_FAILURE)
            return NULL;
        if ((add_alias_in_list(alias->new_name, \
alias->command, alias)) == NULL)
            return NULL;
    }
    free(all_alias);
    fclose(file);
    return alias;
}

FILE *_42rc_is_filled(void)
{
    FILE *stream = NULL;
    int first_char = 0;
    int fd = 0;

    if ((fd = open(".42rc", O_RDONLY | O_APPEND | O_CREAT, S_IRWXU | S_IRWXG | S_IRWXO)) == -1)
        exit(84);
    stream = fdopen(fd, "r");
    if (stream == NULL)
        exit(84);
    first_char = fgetc(stream);
    if (first_char == EOF)
        return NULL;
    close(fd);
    return stream;
}
