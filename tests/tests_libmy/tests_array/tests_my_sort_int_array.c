/*
** EPITECH PROJECT, 2018
** LIBMY - UNIT TEST
** File description:
** Unit Tests for my_sort_int_array function
*/

#include "my.h"
#include "unittest.h"

Test(my_sort_int_array, test_00)
{
    int array[] = {4, 3, 2, 1};
    my_sort_int_array(array, 4);
    cr_expect_eq(array[0], 1);
    cr_expect_eq(array[1], 2);
    cr_expect_eq(array[2], 3);
    cr_expect_eq(array[3], 4);
}

Test(my_sort_int_array, test_01)
{
    int array[] = {4, -3, 2, -1};
    my_sort_int_array(array, 4);
    cr_expect_eq(array[0], -3);
    cr_expect_eq(array[1], -1);
    cr_expect_eq(array[2], 2);
    cr_expect_eq(array[3], 4);
}

Test(my_sort_int_array, test_02)
{
    int array[] = {1, 2, 3, 4};
    my_sort_int_array(array, 4);
    cr_expect_eq(array[0], 1);
    cr_expect_eq(array[1], 2);
    cr_expect_eq(array[2], 3);
    cr_expect_eq(array[3], 4);
}

Test(my_sort_int_array, test_03)
{
    int array[] = {0, 0, 0, 0};
    my_sort_int_array(array, 4);
    cr_expect_eq(array[0], 0);
    cr_expect_eq(array[1], 0);
    cr_expect_eq(array[2], 0);
    cr_expect_eq(array[3], 0);
}

Test(my_sort_int_array, test_04)
{
    int array[] = {4, 2, -6};
    my_sort_int_array(array, 3);
    cr_expect_eq(array[0], -6);
    cr_expect_eq(array[1], 2);
    cr_expect_eq(array[2], 4);
}
