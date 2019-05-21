/*
** EPITECH PROJECT, 2019
** 42SH
** File description:
** my_segfault
*/

#include <unistd.h>
#include <signal.h>
#include <sys/types.h>

int main(void)
{
    kill(getpid(), SIGSEGV);
    return (0);
}
