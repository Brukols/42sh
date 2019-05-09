/*
** EPITECH PROJECT, 2018
** LIBMY - UNIT TEST
** File description:
** Unit Tests for my_getnbr function
*/

#include "my.h"
#include "unittest.h"

Test(my_getnbr, test_00)
{
    cr_expect_eq(my_getnbr("-678"), -678);
}

Test(my_getnbr, test_01)
{
    cr_expect_eq(my_getnbr("--++-4"), -4);
}

Test(my_getnbr, test_02)
{
    cr_expect_eq(my_getnbr("1234567890"), 1234567890);
}

Test(my_getnbr, test_03)
{
    cr_expect_eq(my_getnbr("001r"), 1);
}

Test(my_getnbr, test_04)
{
    cr_expect_eq(my_getnbr("-r45r56T5"), 0);
}
