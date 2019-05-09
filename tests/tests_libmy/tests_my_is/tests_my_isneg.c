/*
** EPITECH PROJECT, 2018
** LIBMY - UNIT TEST
** File description:
** Unit Tests for my_isneg
*/

#include "my.h"
#include "unittest.h"

Test(my_isneg, test_00)
{
    cr_expect_eq(my_isneg(43567989), 0);
}

Test(my_isneg, test_01)
{
    cr_expect_eq(my_isneg(-7), 1);
}

Test(my_isneg, test_02)
{
    cr_expect_eq(my_isneg(-0), 0);
}

Test(my_isneg, test_03)
{
    cr_expect_eq(my_isneg(0), 0);
}

Test(my_isneg, test_04)
{
    cr_expect_eq(my_isneg(-678), 1);
}
