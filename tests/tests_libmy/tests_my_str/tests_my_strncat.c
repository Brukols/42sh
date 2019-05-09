/*
** EPITECH PROJECT, 2018
** LIBMY - UNIT TEST
** File description:
** Unit Tests for my_strncat function
*/

#include "my.h"
#include "unittest.h"

Test(my_strncat, test_00)
{
    char *test = malloc(sizeof(char) * 10);
    test[0] = 'A';
    test[1] = 'B';
    cr_assert_str_eq(my_strncat(test, "Hello", 3), "ABHel");
    free(test);
}

Test(my_strncat, test_01)
{
    char *test = malloc(sizeof(char) * 10);
    cr_assert_str_eq(my_strncat(test, "   bonjour\n", 11), "   bonjour\n");
    free(test);
}

Test(my_strncat, test_02)
{
    char *test = malloc(sizeof(char) * 10);
    cr_assert_str_eq(my_strncat(test, "123(_)", 1), "1");
    free(test);
}

Test(my_strncat, test_03)
{
    char *test = malloc(sizeof(char) * 10);
    cr_assert_str_eq(my_strncat(test, "", 3), "");
    free(test);
}

Test(my_strncat, test_04)
{
    char *test = malloc(sizeof(char) * 10);
    test[0] = 'A';
    test[1] = 'B';
    test[2] = '\t';
    cr_assert_str_eq(my_strncat(test, "Hello\t", 4), "AB\tHell");
    free(test);
}
