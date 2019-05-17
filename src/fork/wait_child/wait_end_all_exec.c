/*
** EPITECH PROJECT, 2019
** 42SH
** File description:
** wait_end_all_exec
*/

#include "shell.h"

void test_segfault(t_info *shell)
{
    if (WCOREDUMP(shell->status)) {
        my_printe("Segmentation fault (core dumped)\n");
    } else {
        my_printe("Segmentation fault\n");
    }
}

int wait_end_all_exec(t_info *shell)
{
    int exit_status = 0;
    while (wait(&shell->status) != -1) {
        if (WIFSIGNALED(shell->status)) {
            if (WTERMSIG(shell->status) == SIGSEGV) {
                test_segfault(shell);
            }
            if (WTERMSIG(shell->status) == 8)
                my_printe("Floating exception\n");
        }
        if (WIFEXITED(shell->status))
            exit_status += WEXITSTATUS(shell->status);
        shell->status = 0;
    }
    return (exit_status);
}
