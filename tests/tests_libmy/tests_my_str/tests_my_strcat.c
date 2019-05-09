/*
** EPITECH PROJECT, 2018
** LIBMY - UNIT TEST
** File description:
** Unit Tests for my_strcat function
*/

#include "my.h"
#include "unittest.h"

Test(my_strcat, test_00)
{
    char *test = malloc(sizeof(char) * 10);
    test[0] = 'A';
    test[1] = 'B';
    cr_assert_str_eq(my_strcat(test, "Hello"), "ABHello");
    free(test);
}

Test(my_strcat, test_01)
{
    char *test = malloc(sizeof(char) * 10);
    cr_assert_str_eq(my_strcat(test, "   \n"), "   \n");
    free(test);
}

Test(my_strcat, test_02)
{
    char *test = malloc(sizeof(char) * 10);
    cr_assert_str_eq(my_strcat(test, "123(_)"), "123(_)");
    free(test);
}

Test(my_strcat, test_03)
{
    char *test = malloc(sizeof(char) * 10);
    cr_assert_str_eq(my_strcat(test, ""), "");
    free(test);
}

Test(my_strcat, test_04)
{
    char *test = malloc(sizeof(char) * 10);
    cr_assert_str_eq(my_strcat(test, "Hello\t"), "Hello\t");
    free(test);
}
