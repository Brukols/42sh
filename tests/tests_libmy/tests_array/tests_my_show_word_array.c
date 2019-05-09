/*
** EPITECH PROJECT, 2018
** LIBMY - UNIT TEST
** File description:
** Unit Tests for my_show_word_array function
*/

#include "my.h"
#include "unittest.h"

Test(my_show_word_array, test_00, .init = redirect_all_std)
{
    char **array = my_str_to_word_array("Hello World How Are You?", ' ');
    my_show_word_array(array);
    cr_assert_stdout_eq_str("Hello\nWorld\nHow\nAre\nYou?\n");
    free_array(array);
}

Test(my_show_word_array, test_01, .init = redirect_all_std)
{
    char **array = my_str_to_word_array("Hello\tWorld\tHow\tAre\tYou?", ' ');
    my_show_word_array(array);
    cr_assert_stdout_eq_str("Hello\nWorld\nHow\nAre\nYou?\n");
    free_array(array);
}

Test(my_show_word_array, test_02, .init = redirect_all_std)
{
    char **array = my_str_to_word_array("HelloWorldHowAreYou?", ' ');
    my_show_word_array(array);
    cr_assert_stdout_eq_str("HelloWorldHowAreYou?\n");
    free_array(array);
}

Test(my_show_word_array, test_03, .init = redirect_all_std)
{
    char **array = my_str_to_word_array("Hello\tWorld\tHow\tAre\t\tYou?", 'o');
    my_show_word_array(array);
    cr_assert_stdout_eq_str("Hell\nW\nrld\nH\nw\nAre\nY\nu?\n");
    free_array(array);
}

Test(my_show_word_array, test_04, .init = redirect_all_std)
{
    char **array = my_str_to_word_array("test\n", ' ');
    my_show_word_array(array);
    cr_assert_stdout_eq_str("test\n");
    free_array(array);
}
