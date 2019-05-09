/*
** EPITECH PROJECT, 2018
** LIBMY - UNIT TEST
** File description:
** Unit Tests for emy_put_nbr_octal function
*/

#include "my.h"
#include "unittest.h"

Test(emy_put_nbr_octal, test_00, .init = redirect_all_std)
{
    emy_put_nbr_octal(43567877);
    cr_assert_stderr_eq_str("246145405");
}

Test(emy_put_nbr_octal, test_01, .init = redirect_all_std)
{
    emy_put_nbr_octal(4);
    cr_assert_stderr_eq_str("4");
}

Test(emy_put_nbr_octal, test_02, .init = redirect_all_std)
{
    emy_put_nbr_octal(0);
    cr_assert_stderr_eq_str("0");
}

Test(emy_put_nbr_octal, test_03, .init = redirect_all_std)
{
    emy_put_nbr_octal(43);
    cr_assert_stderr_eq_str("53");
}

Test(emy_put_nbr_octal, test_04, .init = redirect_all_std)
{
    emy_put_nbr_octal(15);
    cr_assert_stderr_eq_str("17");
}
