/*
** EPITECH PROJECT, 2018
** LIBMY - UNIT TEST
** File description:
** Unit Tests for my_calloc function
*/

#include "my.h"
#include "unittest.h"

Test(my_calloc, test_00)
{
    char *str = my_calloc(12, 12);
    cr_assert_str_eq(str, "");
}
