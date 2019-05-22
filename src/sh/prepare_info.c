/*
** EPITECH PROJECT, 2019
** 42SH
** File description:
** prepare_info
*/

#include "shell.h"

int is_scripting(int argc, char **argv)
{
    int fd = 0;
    char *shebang = NULL;

    if (argc != 2)
        return (fd);
    fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        my_printe("Error with scripting file\n");
        return (0);
    }
    shebang = get_next_line(fd);
    if (shebang)
        free(shebang);
    return (fd);
}

t_info *prepare_info(int argc, char **argv, char **env)
{
    t_info *shell = malloc(sizeof(t_info));

    if (shell == NULL)
        return (NULL);
    my_memset(shell, 0, sizeof(t_info));
    if ((shell->builtin = init_builtin()) == NULL)
        return (NULL);
    shell->env = my_array_cpy(env);
    if (shell->env == NULL)
        return (delete_all(shell));
    shell->fd_read = is_scripting(argc, argv);
    shell->stdin_o = dup(STDIN_FILENO);
    shell->stdou_o = dup(STDOUT_FILENO);
    return (shell);
}
