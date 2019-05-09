/*
** EPITECH PROJECT, 2018
** LIBMY - UNIT TEST
** File description:
** Unit Tests for my_is_prime function
*/

#include "my.h"
#include "unittest.h"

Test(my_is_prime, test_00)
{
    cr_expect_eq(my_is_prime(1), 0);
}

Test(my_is_prime, test_01)
{
    cr_expect_eq(my_is_prime(0), 0);
}

Test(my_is_prime, test_02)
{
    cr_expect_eq(my_is_prime(34567), 0);
}

Test(my_is_prime, test_03)
{
    cr_expect_eq(my_is_prime(-5), 0);
}

Test(my_is_prime, test_04)
{
    cr_expect_eq(my_is_prime(2), 1);
}
