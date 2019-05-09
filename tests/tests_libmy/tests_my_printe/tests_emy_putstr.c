/*
** EPITECH PROJECT, 2018
** LIBMY - UNIT TEST
** File description:
** Unit Tests for emy_putstr function
*/

#include "my.h"
#include "unittest.h"

Test(emy_putstr, test_00, .init = redirect_all_std)
{
    emy_putstr("Hello World\n");
    cr_assert_stderr_eq_str("Hello World\n");
}

Test(emy_putstr, test_01, .init = redirect_all_std)
{
    emy_putstr("H");
    cr_assert_stderr_eq_str("H");
}

Test(emy_putstr, test_02, .init = redirect_all_std)
{
    emy_putstr("0123456789");
    cr_assert_stderr_eq_str("0123456789");
}

Test(emy_putstr, test_03, .init = redirect_all_std)
{
    emy_putstr("0\n");
    cr_assert_stderr_eq_str("0\n");
}

Test(emy_putstr, test_04, .init = redirect_all_std)
{
    emy_putstr("Hel0\n");
    cr_assert_stderr_eq_str("Hel0\n");
}
