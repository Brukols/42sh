/*
** EPITECH PROJECT, 2018
** LIBMY - UNIT TEST
** File description:
** Unit Tests for my_put_nbr_octal function
*/

#include "my.h"
#include "unittest.h"

Test(my_put_nbr_octal, test_00, .init = redirect_all_std)
{
    my_put_nbr_octal(43567877);
    cr_assert_stdout_eq_str("246145405");
}

Test(my_put_nbr_octal, test_01, .init = redirect_all_std)
{
    my_put_nbr_octal(4);
    cr_assert_stdout_eq_str("4");
}

Test(my_put_nbr_octal, test_02, .init = redirect_all_std)
{
    my_put_nbr_octal(0);
    cr_assert_stdout_eq_str("0");
}

Test(my_put_nbr_octal, test_03, .init = redirect_all_std)
{
    my_put_nbr_octal(43);
    cr_assert_stdout_eq_str("53");
}

Test(my_put_nbr_octal, test_04, .init = redirect_all_std)
{
    my_put_nbr_octal(15);
    cr_assert_stdout_eq_str("17");
}
