/*
** EPITECH PROJECT, 2018
** PROJECT
** File description:
** Unit Tests for
*/

#include "header.h"
#include "unittest.h"

Test(my_printf, simple_string, .init = redirect_all_std)
{
    my_printf("hello world");
    cr_assert_stdout_eq_str("hello world");
}

Test(my_printf, simple_string_1, .init = redirect_all_std)
{
    char str[9];
    my_strcpy(str, "Benjamin");
    int age = 18;
    my_printf("Bonjour je m'appelle %s et j'ai %%%i ans", str, age);
    cr_assert_stdout_eq_str("Bonjour je m'appelle Benjamin et j'ai %18 ans");
}

Test(my_printf, simple_string_2, .init = redirect_all_std)
{
    my_printf("%%s%%dAstek42%%", "s", 23);
    cr_assert_stdout_eq_str("%s%dAstek42%");
}

Test(my_printf, simple_string_3, .init = redirect_all_std)
{
    my_printf("%%%%%% %%% %%%%%%% %%%d", 23);
    cr_assert_stdout_eq_str("%%% %% %%%% %23");
}
