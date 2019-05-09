/*
** EPITECH PROJECT, 2018
** LIBMY - UNIT TEST
** File description:
** Unit Tests for my_printe function
*/

#include "my.h"
#include "unittest.h"

Test(my_printe, simple_string, .init = redirect_all_std)
{
    my_printe("hello world");
    cr_assert_stderr_eq_str("hello world");
}

Test(my_printe, simple_string_1, .init = redirect_all_std)
{
    char str[9];
    my_strcpy(str, "Benjamin");
    int age = 18;
    my_printe("Bonjour je m'appelle %s et j'ai %%%i ans", str, age);
    cr_assert_stderr_eq_str("Bonjour je m'appelle Benjamin et j'ai %18 ans");
}

Test(my_printe, simple_string_2, .init = redirect_all_std)
{
    my_printe("%%s%%dAstek42%%", "s", 23);
    cr_assert_stderr_eq_str("%s%dAstek42%");
}

Test(my_printe, simple_string_3, .init = redirect_all_std)
{
    my_printe("%%%%%% %%% %%%%%%% %%%d", 23);
    cr_assert_stderr_eq_str("%%% %% %%%% %23");
}

Test(my_printe, simple_string_4, .init = redirect_all_std)
{
    int i = 1;
    int j = -56;
    my_printe("%c = %i et %c = %i", 'i', i, 'j', j);
    cr_assert_stderr_eq_str("i = 1 et j = -56");
}
