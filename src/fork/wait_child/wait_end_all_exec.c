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

void wait_end_all_exec(t_info *shell)
{
    waitpid(shell->child_pid, &shell->status, WUNTRACED | WCONTINUED);
    if (WIFSIGNALED(shell->status)) {
        if (WTERMSIG(shell->status) == SIGSEGV) {
            test_segfault(shell);
        }
        if (WTERMSIG(shell->status) == 8)
            my_printe("Floating exception\n");
    }
}
