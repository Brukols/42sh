/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** my_strcmp
*/

#include "my.h"

int my_strcmp(char const *s1, char const *s2)
{
    for (int i = 0; i < my_strlen(s1) && i < my_strlen(s2); i++) {
        if (s1[i] > s2[i])
            return 1;
        else if (s1[i] < s2[i])
            return -1;
    }
    return 0;
}
