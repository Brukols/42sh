/*
** EPITECH PROJECT, 2018
** LIBMY - UNIT TEST
** File description:
** Unit Tests for my_memset function
*/

#include "my.h"
#include "unittest.h"

Test(my_memset, test_00)
{
    char *str = malloc(sizeof(char) * 12);
    my_memset(str, 'A', 12);
    cr_assert_str_eq(str, "AAAAAAAAAAAA");
}

Test(my_memset, test_01)
{
    char *str = malloc(sizeof(char) * 12);
    str = my_memset(NULL, 'A', 12);
    cr_assert_eq(str, NULL);
}

Test(my_memset, test_02)
{
    char *str = malloc(sizeof(char) * 12);
    my_memset(str, '\0', 12);
    cr_assert_str_eq(str, "");
}

Test(my_memset, test_03)
{
    char *str = malloc(sizeof(char) * 12);
    my_memset(str, '\t', 12);
    cr_assert_str_eq(str, "\t\t\t\t\t\t\t\t\t\t\t\t");
}

Test(my_memset, test_04)
{
    char *str = malloc(sizeof(char) * 12);
    my_memset(str, '\n', 1);
    cr_assert_str_eq(str, "\n");
}
