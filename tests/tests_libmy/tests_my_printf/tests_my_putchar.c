/*
** EPITECH PROJECT, 2018
** LIBMY - UNIT TEST
** File description:
** Unit Tests for my_putchar function
*/

#include "my.h"
#include "unittest.h"

Test(my_putchar, test_00, .init = redirect_all_std)
{
    my_putchar('c');
    cr_assert_stdout_eq_str("c");
}

Test(my_putchar, test_01, .init = redirect_all_std)
{
    my_putchar('{');
    cr_assert_stdout_eq_str("{");
}

Test(my_putchar, test_02, .init = redirect_all_std)
{
    my_putchar('5');
    cr_assert_stdout_eq_str("5");
}

Test(my_putchar, test_03, .init = redirect_all_std)
{
    my_putchar(' ');
    cr_assert_stdout_eq_str(" ");
}

Test(my_putchar, test_04, .init = redirect_all_std)
{
    my_putchar('%');
    cr_assert_stdout_eq_str("%");
}
