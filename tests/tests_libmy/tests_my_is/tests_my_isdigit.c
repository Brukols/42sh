/*
** EPITECH PROJECT, 2018
** LIBMY - UNIT TEST
** File description:
** Unit Tests for my_isdigit function
*/

#include "my.h"
#include "unittest.h"

Test(my_isdigit, test_00)
{
    cr_expect_eq(my_isdigit('c'), 0);
}

Test(my_isdigit, test_01)
{
    cr_expect_eq(my_isdigit('9'), 1);
}

Test(my_isdigit, test_02)
{
    cr_expect_eq(my_isdigit('%'), 0);
}

Test(my_isdigit, test_03)
{
    cr_expect_eq(my_isdigit('*'), 0);
}

Test(my_isdigit, test_04)
{
    cr_expect_eq(my_isdigit('-'), 0);
}
