/*
** EPITECH PROJECT, 2018
** LIBMY - UNIT TEST
** File description:
** Unit Tests for emy_putstr_np function
*/

#include "my.h"
#include "unittest.h"

Test(emy_putstr_np, test_00, .init = redirect_all_std)
{
    char str[5];
    my_strcpy(str, "toto");
    str[1] = 6;

    emy_putstr_np(str);
    cr_assert_stderr_eq_str("t\\006to");
}

Test(emy_putstr_np, test_01, .init = redirect_all_std)
{
    char str[5];
    my_strcpy(str, "toto");
    str[1] = 7;

    emy_putstr_np(str);
    cr_assert_stderr_eq_str("t\\007to");
}

Test(emy_putstr_np, test_02, .init = redirect_all_std)
{
    char str[5];
    my_strcpy(str, "toto");
    str[1] = 10;

    emy_putstr_np(str);
    cr_assert_stderr_eq_str("t\\012to");
}
