/*
** EPITECH PROJECT, 2018
** LIBMY - UNIT TEST
** File description:
** Unit Tests for my_strupcase function
*/

#include "my.h"
#include "unittest.h"

Test(my_strupcase, test_00)
{
    char *test = my_strdup("Hello");
    cr_assert_str_eq(my_strupcase(test), "HELLO");
    free(test);
}

Test(my_strupcase, test_01)
{
    char *test = my_strdup("BONJouR\n");
    cr_assert_str_eq(my_strupcase(test), "BONJOUR\n");
    free(test);
}

Test(my_strupcase, test_02)
{
    char *test = my_strdup("123 ONe TesT");
    cr_assert_str_eq(my_strupcase(test), "123 ONE TEST");
    free(test);
}

Test(my_strupcase, test_03)
{
    char *test = my_strdup("+56\t");
    cr_assert_str_eq(my_strupcase(test), "+56\t");
    free(test);
}

Test(my_strupcase, test_04)
{
    char *test = my_strdup("");
    cr_assert_str_eq(my_strupcase(test), "");
    free(test);
}
