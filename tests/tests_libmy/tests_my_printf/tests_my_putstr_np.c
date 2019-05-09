/*
** EPITECH PROJECT, 2018
** LIBMY - UNIT TEST
** File description:
** Unit Tests for my_putstr_np function
*/

#include "my.h"
#include "unittest.h"

Test(my_putstr_np, test_00, .init = redirect_all_std)
{
    char str[5];
    my_strcpy(str, "toto");
    str[1] = 6;

    my_putstr_np(str);
    cr_assert_stdout_eq_str("t\\006to");
}

Test(my_putstr_np, test_01, .init = redirect_all_std)
{
    char str[5];
    my_strcpy(str, "toto");
    str[1] = 7;

    my_putstr_np(str);
    cr_assert_stdout_eq_str("t\\007to");
}

Test(my_putstr_np, test_02, .init = redirect_all_std)
{
    char str[5];
    my_strcpy(str, "toto");
    str[1] = 10;

    my_putstr_np(str);
    cr_assert_stdout_eq_str("t\\012to");
}
