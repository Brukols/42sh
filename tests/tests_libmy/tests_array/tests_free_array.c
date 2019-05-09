/*
** EPITECH PROJECT, 2018
** LIBMY - UNIT TEST
** File description:
** Unit Tests for free_array function
*/

#include "my.h"
#include "unittest.h"

Test(free_array, test_00)
{
    char **array = malloc(sizeof(char *) * 4);
    array[0] = my_strdup("0");
    array[1] = my_strdup("1");
    array[2] = my_strdup("2");
    array[3] = NULL;
    free_array(array);
    cr_assume_null(array[3]);
}

Test(free_array, test_01)
{
    char **array = NULL;
    free_array(array);
    cr_assume_null(array);
}
