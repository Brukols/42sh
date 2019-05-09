/*
** EPITECH PROJECT, 2018
** LIBMY - UNIT TEST
** File description:
** Unit Tests for is_flag function
*/

#include "my.h"
#include "unittest.h"

Test(is_flag, test_00)
{
    cr_expect_eq(is_flag('c'), 1);
}

Test(is_flag, test_01)
{
    cr_expect_eq(is_flag('X'), 1);
}

Test(is_flag, test_02)
{
    cr_expect_eq(is_flag('q'), 0);
}

Test(is_flag, test_03)
{
    cr_expect_eq(is_flag('%'), 1);
}

Test(is_flag, test_04)
{
    cr_expect_eq(is_flag(' '), 0);
}
