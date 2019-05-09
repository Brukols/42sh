/*
** EPITECH PROJECT, 2018
** PROJECT - UNIT TEST
** File description:
** Unit Tests for my_strlen function
*/

#include "my.h"
#include "unittest.h"

Test(my_strlen, test_00)
{
    cr_expect_eq(my_strlen("abcd"), 4);
}

Test(my_strlen, test_01)
{
    cr_expect_eq(my_strlen("Hello World\t\n"), 13);
}

Test(my_strlen, test_02)
{
    cr_expect_eq(my_strlen("    \n\t  "), 8);
}

Test(my_strlen, test_03)
{
    cr_expect_eq(my_strlen("123456 7890"), 11);
}

Test(my_strlen, test_04)
{
    cr_expect_eq(my_strlen(""), 0);
}
