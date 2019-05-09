/*
** EPITECH PROJECT, 2018
** LIBMY - UNIT TEST
** File description:
** Unit Tests for my_put_nbr_binary function
*/

#include "my.h"
#include "unittest.h"

Test(my_put_nbr_binary, test_00, .init = redirect_all_std)
{
    my_put_nbr_binary(43567877);
    cr_assert_stdout_eq_str("10100110001100101100000101");
}

Test(my_put_nbr_binary, test_01, .init = redirect_all_std)
{
    my_put_nbr_binary(1);
    cr_assert_stdout_eq_str("1");
}

Test(my_put_nbr_binary, test_02, .init = redirect_all_std)
{
    my_put_nbr_binary(0);
    cr_assert_stdout_eq_str("0");
}

Test(my_put_nbr_binary, test_03, .init = redirect_all_std)
{
    my_put_nbr_binary(2);
    cr_assert_stdout_eq_str("10");
}

Test(my_put_nbr_binary, test_04, .init = redirect_all_std)
{
    my_put_nbr_binary(1111);
    cr_assert_stdout_eq_str("10001010111");
}
