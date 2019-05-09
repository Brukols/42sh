/*
** EPITECH PROJECT, 2018
** LIBMY - UNIT TEST
** File description:
** Unit Tests for my_strcapitalize function
*/

#include "my.h"
#include "unittest.h"

Test(my_strcapitalize, test_00)
{
    char *test = my_strdup("Hello");
    cr_assert_str_eq(my_strcapitalize(test), "Hello");
    free(test);
}

Test(my_strcapitalize, test_01)
{
    char *test = my_strdup("BONJouR\n");
    cr_assert_str_eq(my_strcapitalize(test), "Bonjour\n");
    free(test);
}

Test(my_strcapitalize, test_02)
{
    char *test = my_strdup("un test");
    cr_assert_str_eq(my_strcapitalize(test), "Un Test");
    free(test);
}

Test(my_strcapitalize, test_03)
{
    char *test = my_strdup("+56");
    cr_assert_str_eq(my_strcapitalize(test), "+56");
    free(test);
}

Test(my_strcapitalize, test_04)
{
    char *test = my_strdup("");
    cr_assert_str_eq(my_strcapitalize(test), "");
    free(test);
}
