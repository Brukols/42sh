/*
** EPITECH PROJECT, 2018
** libmy - my_printf
** File description:
** my_printf
*/

#include "my.h"

int my_printf(const char *str, ...)
{
    int i = 0;
    va_list arg;
    va_start(arg, str);

    while (str[i] != '\0') {
        if (str[i] == '%' && is_flag(str[i + 1]) == 1) {
            i++;
            if (str[i] == '%')
                my_putchar('%');
            else
                sort_flags(str[i], va_arg(arg, void *));
        } else {
            my_putchar(str[i]);
        }
        i++;
    }
    return 0;
}
