/*
** EPITECH PROJECT, 2018
** LIBMY - UNIT TEST
** File description:
** Unit Tests for my_find_prime_sup function
*/

#include "my.h"
#include "unittest.h"

Test(my_find_prime_sup, test_00)
{
    cr_expect_eq(my_find_prime_sup(3), 3);
}

Test(my_find_prime_sup, test_01)
{
    cr_expect_eq(my_find_prime_sup(4), 5);
}

Test(my_find_prime_sup, test_02)
{
    cr_expect_eq(my_find_prime_sup(90), 97);
}

Test(my_find_prime_sup, test_03)
{
    cr_expect_eq(my_find_prime_sup(50), 53);
}

Test(my_find_prime_sup, test_04)
{
    cr_expect_eq(my_find_prime_sup(-49), 2);
}
