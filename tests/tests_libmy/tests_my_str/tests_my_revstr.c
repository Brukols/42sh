/*
** EPITECH PROJECT, 2018
** LIBMY - UNIT TEST
** File description:
** Unit Tests for my_revstr function
*/

#include "my.h"
#include "unittest.h"

Test(my_revstr, test_00)
{
    char *test = my_strdup("Hello");
    cr_assert_str_eq(my_revstr(test), "olleH");
    free(test);
}

Test(my_revstr, test_01)
{
    char *test = my_strdup("BONJouR\n");
    cr_assert_str_eq(my_revstr(test), "\nRuoJNOB");
    free(test);
}

Test(my_revstr, test_02)
{
    char *test = my_strdup("un test");
    cr_assert_str_eq(my_revstr(test), "tset nu");
    free(test);
}

Test(my_revstr, test_03)
{
    char *test = my_strdup("+56");
    cr_assert_str_eq(my_revstr(test), "65+");
    free(test);
}

Test(my_revstr, test_04)
{
    char *test = my_strdup("");
    cr_assert_str_eq(my_revstr(test), "");
    free(test);
}
