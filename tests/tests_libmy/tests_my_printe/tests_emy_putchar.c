/*
** EPITECH PROJECT, 2018
** LIBMY - UNIT TEST
** File description:
** Unit Tests for emy_putchar function
*/

#include "my.h"
#include "unittest.h"

Test(emy_putchar, test_00, .init = redirect_all_std)
{
    emy_putchar('c');
    cr_assert_stderr_eq_str("c");
}

Test(emy_putchar, test_01, .init = redirect_all_std)
{
    emy_putchar('{');
    cr_assert_stderr_eq_str("{");
}

Test(emy_putchar, test_02, .init = redirect_all_std)
{
    emy_putchar('5');
    cr_assert_stderr_eq_str("5");
}

Test(emy_putchar, test_03, .init = redirect_all_std)
{
    emy_putchar(' ');
    cr_assert_stderr_eq_str(" ");
}

Test(emy_putchar, test_04, .init = redirect_all_std)
{
    emy_putchar('%');
    cr_assert_stderr_eq_str("%");
}
