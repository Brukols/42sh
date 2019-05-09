/*
** EPITECH PROJECT, 2018
** LIBMY - UNIT TEST
** File description:
** Unit Tests for emy_put_nbr function
*/

#include "my.h"
#include "unittest.h"

Test(emy_put_nbr, test_00, .init = redirect_all_std)
{
    emy_put_nbr(43567877);
    cr_assert_stderr_eq_str("43567877");
}

Test(emy_put_nbr, test_01, .init = redirect_all_std)
{
    emy_put_nbr(0);
    cr_assert_stderr_eq_str("0");
}

Test(emy_put_nbr, test_02, .init = redirect_all_std)
{
    emy_put_nbr(-0);
    cr_assert_stderr_eq_str("0");
}

Test(emy_put_nbr, test_03, .init = redirect_all_std)
{
    emy_put_nbr(-43567877);
    cr_assert_stderr_eq_str("-43567877");
}

Test(emy_put_nbr, test_04, .init = redirect_all_std)
{
    emy_put_nbr(2147483647);
    cr_assert_stderr_eq_str("2147483647");
}
