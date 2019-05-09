/*
** EPITECH PROJECT, 2018
** PROJECT - UNIT TEST
** File description:
** Unit Tests for my_strcmp function
*/

#include "my.h"
#include "unittest.h"

Test(my_strcmp, test_00)
{
    cr_expect_eq(my_strcmp("abcd", "bacd"), -1);
}

Test(my_strcmp, test_01)
{
    cr_expect_eq(my_strcmp("Hello World\t\n", "Hello World\t\n"), 0);
}

Test(my_strcmp, test_02)
{
    cr_expect_eq(my_strcmp("    ", "     "), 0);
}

Test(my_strcmp, test_03)
{
    cr_expect_eq(my_strcmp("bacd", "abcd"), 1);
}

Test(my_strcmp, test_04)
{
    cr_expect_eq(my_strcmp("djizad123", "djizad123"), 0);
}
