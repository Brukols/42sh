/*
** EPITECH PROJECT, 2018
** LIBMY - UNIT TEST
** File description:
** Unit Tests for get_size_array function
*/

#include "my.h"
#include "unittest.h"

Test(get_size_array, test_00)
{
    char **array = malloc(sizeof(char *) * 4);
    array[0] = my_strdup("0");
    array[1] = my_strdup("1");
    array[2] = my_strdup("2");
    array[3] = NULL;
    cr_expect_eq(get_size_array(array), 3);
    free_array(array);
}

Test(get_size_array, test_01)
{
    char **array = malloc(sizeof(char *) * 4);
    array[0] = NULL;
    cr_expect_eq(get_size_array(array), 0);
    free_array(array);
}

Test(get_size_array, test_02)
{
    char **array = malloc(sizeof(char *) * 4);
    array[0] = my_strdup("0");
    array[1] = NULL;
    array[2] = my_strdup("2");
    array[3] = NULL;
    cr_expect_eq(get_size_array(array), 1);
    free_array(array);
}

Test(get_size_array, test_03)
{
    char **array = malloc(sizeof(char *) * 4);
    array[0] = my_strdup("0");
    array[1] = my_strdup("1");
    array[2] = my_strdup("2");
    array[3] = NULL;
    cr_expect_eq(get_size_array(array), 3);
    free_array(array);
}

Test(get_size_array, test_04)
{
    char **array = malloc(sizeof(char *) * 12);
    array[0] = my_strdup("0");
    array[1] = my_strdup("1");
    array[2] = my_strdup("2");
    array[3] = my_strdup("3");
    array[4] = my_strdup("4");
    array[5] = my_strdup("5");
    array[6] = my_strdup("6");
    array[7] = my_strdup("7");
    array[8] = my_strdup("8");
    array[9] = my_strdup("9");
    array[10] = my_strdup("10");
    array[11] = NULL;
    cr_expect_eq(get_size_array(array), 11);
    free_array(array);
}
