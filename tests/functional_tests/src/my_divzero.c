/*
** EPITECH PROJECT, 2019
** 42SH
** File description:
** my_divzero
*/

#include <unistd.h>
#include <signal.h>
#include <sys/types.h>

int main(void)
{
    kill(getpid(), SIGFPE);
    return (0);
}
