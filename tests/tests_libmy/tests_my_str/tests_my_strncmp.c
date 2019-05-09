/*
** EPITECH PROJECT, 2018
** PROJECT - UNIT TEST
** File description:
** Unit Tests for my_strncmp function
*/

#include "my.h"
#include "unittest.h"

Test(my_strncmp, test_00)
{
    cr_expect_eq(my_strncmp("abcd", "bacd", 2), -1);
}

Test(my_strncmp, test_01)
{
    cr_expect_eq(my_strncmp("Hello World\t\n", "Hello World\t\n", 5), 0);
}

Test(my_strncmp, test_02)
{
    cr_expect_eq(my_strncmp("    ", "     ", 7), 0);
}

Test(my_strncmp, test_03)
{
    cr_expect_eq(my_strncmp("bacd", "abcd", 4), 1);
}

Test(my_strncmp, test_04)
{
    cr_expect_eq(my_strncmp("djizad123", "djizad123", 6), 0);
}
