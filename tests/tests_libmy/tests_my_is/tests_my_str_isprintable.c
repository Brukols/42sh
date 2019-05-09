/*
** EPITECH PROJECT, 2018
** LIBMY - UNIT TEST
** File description:
** Unit Tests for my_str_isprintable function
*/

#include "my.h"
#include "unittest.h"

Test(my_str_isprintable, test_00)
{
    cr_expect_eq(my_str_isprintable("AaZzEeRr\n"), 0);
}

Test(my_str_isprintable, test_01)
{
    cr_expect_eq(my_str_isprintable("azertyu\tio"), 0);
}

Test(my_str_isprintable, test_02)
{
    cr_expect_eq(my_str_isprintable("a"), 1);
}

Test(my_str_isprintable, test_03)
{
    cr_expect_eq(my_str_isprintable("111"), 1);
}

Test(my_str_isprintable, test_04)
{
    cr_expect_eq(my_str_isprintable("azerbr1"), 1);
}
