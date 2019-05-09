/*
** EPITECH PROJECT, 2018
** LIBMY - UNIT TEST
** File description:
** Unit Tests for my_swap function
*/

#include "my.h"
#include "unittest.h"

Test(my_swap, test_00)
{
    int a = 1;
    int b = 2;
    my_swap(&a, &b);
    cr_expect_eq(a, 2);
    cr_expect_eq(b, 1);
}

Test(my_swap, test_01)
{
    int a = 1;
    int b = 1;
    my_swap(&a, &b);
    cr_expect_eq(a, 1);
    cr_expect_eq(b, 1);
}

Test(my_swap, test_02)
{
    int a = -1;
    int b = 2;
    my_swap(&a, &b);
    cr_expect_eq(a, 2);
    cr_expect_eq(b, -1);
}

Test(my_swap, test_03)
{
    int a = 109;
    int b = 2;
    my_swap(&a, &b);
    cr_expect_eq(a, 2);
    cr_expect_eq(b, 109);
}

Test(my_swap, test_04)
{
    int a = 100;
    int b = 1000;
    my_swap(&a, &b);
    cr_expect_eq(a, 1000);
    cr_expect_eq(b, 100);
}
