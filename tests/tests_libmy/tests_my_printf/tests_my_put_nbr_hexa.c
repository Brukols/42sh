/*
** EPITECH PROJECT, 2018
** LIBMY - UNIT TEST
** File description:
** Unit Tests for my_put_nbr_hexa function
*/

#include "my.h"
#include "unittest.h"

Test(my_put_nbr_hexa, test_00, .init = redirect_all_std)
{
    my_put_nbr_hexa(43567877);
    cr_assert_stdout_eq_str("298cb05");
}

Test(my_put_nbr_hexa, test_01, .init = redirect_all_std)
{
    my_put_nbr_hexa(4);
    cr_assert_stdout_eq_str("4");
}

Test(my_put_nbr_hexa, test_02, .init = redirect_all_std)
{
    my_put_nbr_hexa(0);
    cr_assert_stdout_eq_str("0");
}

Test(my_put_nbr_hexa, test_03, .init = redirect_all_std)
{
    my_put_nbr_hexa(43);
    cr_assert_stdout_eq_str("2b");
}

Test(my_put_nbr_hexa, test_04, .init = redirect_all_std)
{
    my_put_nbr_hexa(15);
    cr_assert_stdout_eq_str("f");
}
