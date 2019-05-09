/*
** EPITECH PROJECT, 2018
** LIBMY - UNIT TEST
** File description:
** Unit Tests for my_itoa function
*/

#include "my.h"
#include "unittest.h"

Test(my_itoa, test_00)
{
    cr_assert_str_eq(my_itoa(12345), "12345");
}

Test(my_itoa, test_01)
{
    cr_assert_str_eq(my_itoa(-56), "-56");
}

Test(my_itoa, test_02)
{
    cr_assert_str_eq(my_itoa(0), "0");
}

Test(my_itoa, test_03)
{
    cr_assert_str_eq(my_itoa(+56), "56");
}

Test(my_itoa, test_04)
{
    cr_assert_str_eq(my_itoa(66660), "66660");
}
