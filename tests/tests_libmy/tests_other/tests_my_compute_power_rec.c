/*
** EPITECH PROJECT, 2018
** LIBMY - UNIT TEST
** File description:
** Unit Tests for my_compute_power_rec function
*/

#include "my.h"
#include "unittest.h"

Test(my_compute_power_rec, test_00)
{
    cr_expect_eq(my_compute_power_rec(1, 3), 1);
}

Test(my_compute_power_rec, test_01)
{
    cr_expect_eq(my_compute_power_rec(1, 0), 1);
}

Test(my_compute_power_rec, test_02)
{
    cr_expect_eq(my_compute_power_rec(0, 5), 0);
}

Test(my_compute_power_rec, test_03)
{
    cr_expect_eq(my_compute_power_rec(-5, 3), -125);
}

Test(my_compute_power_rec, test_04)
{
    cr_expect_eq(my_compute_power_rec(2, 6), 64);
}
