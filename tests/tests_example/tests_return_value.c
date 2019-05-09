/*
** EPITECH PROJECT, 2018
** PROJECT - UNIT TEST
** File description:
** Unit Tests for
*/

#include "header.h"
#include "unittest.h"

Test(is_flag, return_1)
{
    cr_expect_eq(is_flag('c'), 1);
}

Test(is_flag, return_1_1)
{
    cr_expect_eq(is_flag('X'), 1);
}

Test(is_flag, return_0)
{
    cr_expect_eq(is_flag('q'), 0);
}

Test(is_flag, return_0_1)
{
    cr_expect_eq(is_flag('%'), 1);
}

Test(is_flag, return_0_2)
{
    cr_expect_eq(is_flag(' '), 0);
}