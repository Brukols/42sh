/*
** EPITECH PROJECT, 2018
** LIBMY - UNIT TEST
** File description:
** Unit Tests for my_strcpy function
*/

#include "my.h"
#include "unittest.h"

Test(my_strcpy, test_00)
{
    char *test = malloc(sizeof(char) * 10);
    cr_assert_str_eq(my_strcpy(test, "Hello"), "Hello");
    free(test);
}

Test(my_strcpy, test_01)
{
    char *test = malloc(sizeof(char) * 10);
    cr_assert_str_eq(my_strcpy(test, "   \n"), "   \n");
    free(test);
}

Test(my_strcpy, test_02)
{
    char *test = malloc(sizeof(char) * 10);
    cr_assert_str_eq(my_strcpy(test, "123(_)"), "123(_)");
    free(test);
}

Test(my_strcpy, test_03)
{
    char *test = malloc(sizeof(char) * 10);
    cr_assert_str_eq(my_strcpy(test, ""), "");
    free(test);
}

Test(my_strcpy, test_04)
{
    char *test = malloc(sizeof(char) * 10);
    cr_assert_str_eq(my_strcpy(test, "Hello\t"), "Hello\t");
    free(test);
}
