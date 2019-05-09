/*
** EPITECH PROJECT, 2018
** LIBMY - UNIT TEST
** File description:
** Unit Tests for my_put_nbr_hexa_capitalize function
*/

#include "my.h"
#include "unittest.h"

Test(my_put_nbr_hexa_capitalize, test_00, .init = redirect_all_std)
{
    my_put_nbr_hexa_capitalize(43567877);
    cr_assert_stdout_eq_str("298CB05");
}

Test(my_put_nbr_hexa_capitalize, test_01, .init = redirect_all_std)
{
    my_put_nbr_hexa_capitalize(4);
    cr_assert_stdout_eq_str("4");
}

Test(my_put_nbr_hexa_capitalize, test_02, .init = redirect_all_std)
{
    my_put_nbr_hexa_capitalize(0);
    cr_assert_stdout_eq_str("0");
}

Test(my_put_nbr_hexa_capitalize, test_03, .init = redirect_all_std)
{
    my_put_nbr_hexa_capitalize(43);
    cr_assert_stdout_eq_str("2B");
}

Test(my_put_nbr_hexa_capitalize, test_04, .init = redirect_all_std)
{
    my_put_nbr_hexa_capitalize(15);
    cr_assert_stdout_eq_str("F");
}
