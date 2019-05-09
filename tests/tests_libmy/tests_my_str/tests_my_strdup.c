/*
** EPITECH PROJECT, 2018
** LIBMY - UNIT TEST
** File description:
** Unit Tests for my_strdup function
*/

#include "my.h"
#include "unittest.h"

Test(my_strdup, test_00)
{
    cr_assert_str_eq(my_strdup("12345"), "12345");
}

Test(my_strdup, test_01)
{
    cr_assert_str_eq(my_strdup("-56"), "-56");
}

Test(my_strdup, test_02)
{
    cr_assert_str_eq(my_strdup("Hello World\t\n"), "Hello World\t\n");
}

Test(my_strdup, test_03)
{
    cr_assert_str_eq(my_strdup("12  34"), "12  34");
}

Test(my_strdup, test_04)
{
    cr_assert_str_eq(my_strdup(""), "");
}
