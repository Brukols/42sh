/*
** EPITECH PROJECT, 2018
** LIBMY - UNIT TEST
** File description:
** Unit Tests for my_strlowcase function
*/

#include "my.h"
#include "unittest.h"

Test(my_strlowcase, test_00)
{
    char *test = my_strdup("Hello");
    cr_assert_str_eq(my_strlowcase(test), "hello");
    free(test);
}

Test(my_strlowcase, test_01)
{
    char *test = my_strdup("BONJouR\n");
    cr_assert_str_eq(my_strlowcase(test), "bonjour\n");
    free(test);
}

Test(my_strlowcase, test_02)
{
    char *test = my_strdup("123 ONe TesT");
    cr_assert_str_eq(my_strlowcase(test), "123 one test");
    free(test);
}

Test(my_strlowcase, test_03)
{
    char *test = my_strdup("+56\t");
    cr_assert_str_eq(my_strlowcase(test), "+56\t");
    free(test);
}

Test(my_strlowcase, test_04)
{
    char *test = my_strdup("");
    cr_assert_str_eq(my_strlowcase(test), "");
    free(test);
}
