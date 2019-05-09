/*
** EPITECH PROJECT, 2018
** LIBMY - UNIT TEST
** File description:
** Unit Tests for emy_put_nbr_hexa_capitalize function
*/

#include "my.h"
#include "unittest.h"

Test(emy_put_nbr_hexa_capitalize, test_00, .init = redirect_all_std)
{
    emy_put_nbr_hexa_capitalize(43567877);
    cr_assert_stderr_eq_str("298CB05");
}

Test(emy_put_nbr_hexa_capitalize, test_01, .init = redirect_all_std)
{
    emy_put_nbr_hexa_capitalize(4);
    cr_assert_stderr_eq_str("4");
}

Test(emy_put_nbr_hexa_capitalize, test_02, .init = redirect_all_std)
{
    emy_put_nbr_hexa_capitalize(0);
    cr_assert_stderr_eq_str("0");
}

Test(emy_put_nbr_hexa_capitalize, test_03, .init = redirect_all_std)
{
    emy_put_nbr_hexa_capitalize(43);
    cr_assert_stderr_eq_str("2B");
}

Test(emy_put_nbr_hexa_capitalize, test_04, .init = redirect_all_std)
{
    emy_put_nbr_hexa_capitalize(15);
    cr_assert_stderr_eq_str("F");
}
