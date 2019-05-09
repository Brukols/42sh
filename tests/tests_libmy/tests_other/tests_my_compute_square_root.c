/*
** EPITECH PROJECT, 2018
** LIBMY - UNIT TEST
** File description:
** Unit Tests for my_compute_square_root function
*/

#include "my.h"
#include "unittest.h"

Test(my_compute_square_root, test_00)
{
    cr_expect_eq(my_compute_square_root(3), 0);
}

Test(my_compute_square_root, test_01)
{
    cr_expect_eq(my_compute_square_root(4), 2);
}

Test(my_compute_square_root, test_02)
{
    cr_expect_eq(my_compute_square_root(0), 0);
}

Test(my_compute_square_root, test_03)
{
    cr_expect_eq(my_compute_square_root(1), 1);
}

Test(my_compute_square_root, test_04)
{
    cr_expect_eq(my_compute_square_root(25), 5);
}
