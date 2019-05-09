/*
** EPITECH PROJECT, 2018
** LIBMY - UNIT TEST
** File description:
** Unit Tests for my_is_num function
*/

#include "my.h"
#include "unittest.h"

Test(my_str_is_num, test_00)
{
    cr_expect_eq(my_str_is_num("1234567890"), 1);
}

Test(my_str_is_num, test_01)
{
    cr_expect_eq(my_str_is_num("12345678e"), 0);
}

Test(my_str_is_num, test_02)
{
    cr_expect_eq(my_str_is_num("-456"), 1);
}

Test(my_str_is_num, test_03)
{
    cr_expect_eq(my_str_is_num("45;67"), 0);
}

Test(my_str_is_num, test_04)
{
    cr_expect_eq(my_str_is_num("^"), 0);
}
