/*
** EPITECH PROJECT, 2018
** LIBMY - UNIT TEST
** File description:
** Unit Tests for my_putstr function
*/

#include "my.h"
#include "unittest.h"

Test(my_putstr, test_00, .init = redirect_all_std)
{
    my_putstr("Hello World\n");
    cr_assert_stdout_eq_str("Hello World\n");
}

Test(my_putstr, test_01, .init = redirect_all_std)
{
    my_putstr("H");
    cr_assert_stdout_eq_str("H");
}

Test(my_putstr, test_02, .init = redirect_all_std)
{
    my_putstr("0123456789");
    cr_assert_stdout_eq_str("0123456789");
}

Test(my_putstr, test_03, .init = redirect_all_std)
{
    my_putstr("0\n");
    cr_assert_stdout_eq_str("0\n");
}

Test(my_putstr, test_04, .init = redirect_all_std)
{
    my_putstr("Hel0\n");
    cr_assert_stdout_eq_str("Hel0\n");
}
