/*
** EPITECH PROJECT, 2019
** 42SH
** File description:
** wait_end_all_exec
*/

#include "shell.h"

void test_segfault(t_info *shell, char *error)
{
    if (WCOREDUMP(shell->status))
        my_printe("%s (core dumped)\n", error);
    else
        my_printe("%s\n", error);
}

int wait_end_all_exec(t_info *shell)
{
    int exit_status = 0;

    while (wait(&shell->status) != -1) {
        if (WIFSIGNALED(shell->status)) {
            if (WTERMSIG(shell->status) == SIGSEGV)
                test_segfault(shell, "Segmentation fault");
            if (WTERMSIG(shell->status) == SIGFPE)
                test_segfault(shell, "Floating exception");
        }
        if (WIFEXITED(shell->status))
            exit_status += WEXITSTATUS(shell->status);
        shell->status = 0;
    }
    return (exit_status);
}
