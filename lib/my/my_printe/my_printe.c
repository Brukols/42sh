/*
** EPITECH PROJECT, 2018
** libmy - my_printe
** File description:
** my_printe
*/

#include "my.h"

int my_printe(const char *str, ...)
{
    int i = 0;
    va_list arg;
    va_start(arg, str);

    while (str[i] != '\0') {
        if (str[i] == '%' && is_flag(str[i + 1]) == 1) {
            i++;
            if (str[i] == '%')
                emy_putchar('%');
            else
                esort_flags(str[i], va_arg(arg, void *));
        } else {
            emy_putchar(str[i]);
        }
        i++;
    }
    return 0;
}
