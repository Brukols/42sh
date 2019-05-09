/*
** EPITECH PROJECT, 2018
** PROJECT
** File description:
** Unit Tests for
*/

#include "header.h"
#include "unittest.h"

Test(my_putstr_np, display_correct_0, .init = redirect_all_std)
{
    char str[5];
    my_strcpy(str, "toto");
    str[1] = 6;

    my_putstr_np(str);
    cr_assert_stdout_eq_str("t\\006to");
}

Test(my_putstr_np, display_correct_1, .init = redirect_all_std)
{
    char str[5];
    my_strcpy(str, "toto");
    str[1] = 7;

    my_putstr_np(str);
    cr_assert_stdout_eq_str("t\\007to");
}

Test(my_putstr_np, display_correct_2, .init = redirect_all_std)
{
    char str[5];
    my_strcpy(str, "toto");
    str[1] = 10;

    my_putstr_np(str);
    cr_assert_stdout_eq_str("t\\012to");
}
