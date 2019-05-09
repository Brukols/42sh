/*
** EPITECH PROJECT, 2018
** PROJECT
** File description:
** Unit Tests for
*/

#include "header.h"
#include "unittest.h"

Test(my_put_nbr_binary, display_correct_0, .init = redirect_all_std)
{
    my_put_nbr_binary(43567877);
    cr_assert_stdout_eq_str("10100110001100101100000101");
}

Test(my_put_nbr_binary, display_correct_1, .init = redirect_all_std)
{
    my_put_nbr_binary(1);
    cr_assert_stdout_eq_str("1");
}

Test(my_put_nbr_binary, display_correct_2, .init = redirect_all_std)
{
    my_put_nbr_binary(0);
    cr_assert_stdout_eq_str("0");
}

Test(my_put_nbr_binary, display_correct_3, .init = redirect_all_std)
{
    my_put_nbr_binary(2);
    cr_assert_stdout_eq_str("10");
}

Test(my_put_nbr_binary, display_correct_4, .init = redirect_all_std)
{
    my_put_nbr_binary(1111);
    cr_assert_stdout_eq_str("10001010111");
}