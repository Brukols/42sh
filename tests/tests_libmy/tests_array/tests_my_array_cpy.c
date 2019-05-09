/*
** EPITECH PROJECT, 2018
** LIBMY - UNIT TEST
** File description:
** Unit Tests for my_array_cpy function
*/

#include "my.h"
#include "unittest.h"

Test(my_array_cpy, test_00)
{
    char **array = malloc(sizeof(char *) * 4);
    char **new_array = NULL;
    array[0] = my_strdup("0");
    array[1] = my_strdup("1");
    array[2] = my_strdup("2");
    array[3] = NULL;
    new_array = my_array_cpy(array);
    cr_assert_arr_eq(array[0], new_array[0], 1);
    cr_assert_arr_eq(array[1], new_array[1], 1);
    cr_assert_arr_eq(array[2], new_array[2], 1);
    cr_assume_null(new_array[3]);
    free_array(array);
    free_array(new_array);
}

Test(my_array_cpy, test_01)
{
    char **array = malloc(sizeof(char *) * 4);
    char **new_array = NULL;
    array[0] = my_strdup("Hello ");
    array[1] = my_strdup("World");
    array[2] = my_strdup("\t !");
    array[3] = NULL;
    new_array = my_array_cpy(array);
    cr_assert_arr_eq(array[0], new_array[0], 6);
    cr_assert_arr_eq(array[1], new_array[1], 6);
    cr_assert_arr_eq(array[2], new_array[2], 3);
    cr_assume_null(new_array[3]);
    free_array(array);
    free_array(new_array);
}

Test(my_array_cpy, test_02)
{
    char **array = malloc(sizeof(char *) * 3);
    char **new_array = NULL;
    array[0] = my_strdup("12-34");
    array[1] = my_strdup("AzEr");
    array[2] = NULL;
    new_array = my_array_cpy(array);
    cr_assert_arr_eq(array[0], new_array[0], 5);
    cr_assert_arr_eq(array[1], new_array[1], 4);
    cr_assume_null(new_array[2]);
    free_array(array);
    free_array(new_array);
}

Test(my_array_cpy, test_03)
{
    char **array = malloc(sizeof(char *) * 4);
    char **new_array = NULL;
    array[0] = my_strdup("\t\t\t\n");
    array[1] = my_strdup("\n\n\n\t");
    array[2] = my_strdup("Bonjour\n\t");
    array[3] = NULL;
    new_array = my_array_cpy(array);
    cr_assert_arr_eq(array[0], new_array[0], 4);
    cr_assert_arr_eq(array[1], new_array[1], 4);
    cr_assert_arr_eq(array[2], new_array[2], 9);
    cr_assume_null(new_array[3]);
    free_array(array);
    free_array(new_array);
}

Test(my_array_cpy, test_04)
{
    char **array = malloc(sizeof(char *) * 1);
    char **new_array = NULL;
    array[0] = NULL;
    new_array = my_array_cpy(array);
    cr_assume_null(new_array[0]);
    free_array(array);
    free_array(new_array);
}
