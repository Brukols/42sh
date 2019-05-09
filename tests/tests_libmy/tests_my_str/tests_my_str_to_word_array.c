/*
** EPITECH PROJECT, 2018
** LIBMY - UNIT TEST
** File description:
** Unit Tests for my_str_to_word_array function
*/

#include "my.h"
#include "unittest.h"

Test(my_str_to_word_array, test_00)
{
    char **test = my_str_to_word_array("Hello World How Are You?", ' ');
    cr_assert_arr_eq(test[0], "Hello", 5);
    cr_assert_arr_eq(test[1], "World", 5);
    cr_assert_arr_eq(test[2], "How", 3);
    cr_assert_arr_eq(test[3], "Are", 3);
    cr_assert_arr_eq(test[4], "You?", 4);
}

Test(my_str_to_word_array, test_01)
{
    char **test = my_str_to_word_array("Hello\tWorld\tHow\tAre\tYou?", ' ');
    cr_assert_arr_eq(test[0], "Hello", 5);
    cr_assert_arr_eq(test[1], "World", 5);
    cr_assert_arr_eq(test[2], "How", 3);
    cr_assert_arr_eq(test[3], "Are", 3);
    cr_assert_arr_eq(test[4], "You?", 4);
}

Test(my_str_to_word_array, test_02)
{
    char **test = my_str_to_word_array("HelloWorldHowAreYou?", ' ');
    cr_assert_arr_eq(test[0], "HelloWorldHowAreYou?", 20);
}

Test(my_str_to_word_array, test_03)
{
    char **test = my_str_to_word_array("Hello\tWorld\tHow\tAre\t\tYou?", 'o');
    cr_assert_arr_eq(test[0], "Hell", 4);
    cr_assert_arr_eq(test[1], "W", 1);
    cr_assert_arr_eq(test[2], "rld", 3);
    cr_assert_arr_eq(test[3], "H", 1);
    cr_assert_arr_eq(test[4], "w", 1);
    cr_assert_arr_eq(test[5], "Are", 3);
    cr_assert_arr_eq(test[6], "Y", 1);
    cr_assert_arr_eq(test[7], "u?", 1);

}

Test(my_str_to_word_array, test_04)
{
    char **test = my_str_to_word_array("Hello\tWorld\tHow\tAre\tYou?", 'z');
    cr_assert_arr_eq(test[0], "Hello", 5);
    cr_assert_arr_eq(test[1], "World", 5);
    cr_assert_arr_eq(test[2], "How", 3);
    cr_assert_arr_eq(test[3], "Are", 3);
    cr_assert_arr_eq(test[4], "You?", 4);
}
