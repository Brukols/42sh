/*
** EPITECH PROJECT, 2019
** 42SH
** File description:
** header
*/

#ifndef SHELL_H
#define SHELL_H

#define EXIT_ERROR 84
#include "my.h"
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <fcntl.h>

typedef struct s_info
{
    struct s_builtin **builtin;
    char **env;
    char *command_line;
    char *path;
    int exit;
    int status;
    pid_t child_pid;
    pid_t gr_pid;
    int fd[2];
    int fdd;
    int stdin_o;
    int stdou_o;
    int history;
} t_info;

typedef struct s_list
{
    struct s_command *start;
    int len;
} t_list;

typedef struct s_command
{
    char *command;
    char *separator;
    char **tab_command;
    struct s_command *next;
    struct s_command *prev;
} t_command;

typedef struct s_builtin
{
    char *name;
    int (*ft)(t_info *shell, t_command *command);
} t_builtin;

/* BUILTIN */
t_builtin **init_builtin(void);
int is_builtin(char *name, t_builtin **builtin);
int do_builtin(t_info *shell, int cmd_no, t_command *command);
char *search_env(char **env, char *search);
int verif_arg_env(char **arg);
int is_in_env(char **env, char *new);
char **repair_env(char **env);
/*ENV*/
int my_env(t_info *shell, t_command *command);
/*CD*/
int my_cd(t_info *shell, t_command *command);
int change_dir(char *dir);
int change_old_dir(t_info *shell);
int exec_cd(t_info *shell, t_command *command);
int update_envcd(t_info *shell, char *old_pwd);
int verif_cd(char **tab_command);
/*UNSETENV*/
int my_unsetenv(t_info *shell, t_command *command);
char **exec_unsetenv(char **env, int pos);
char **do_unsetenv(char **env, char *del);
/*SETENV*/
int my_setenv(t_info *shell, t_command *command);
char **replace_venv(char **env, char *name, char *value);
void create_venv(char *new_v, char *name, char *value);
char **add_venv(char **env, char *name, char *value);
/* BUILTIN REDIRECTION */
int builtin_redirection(t_info *shell, t_command *command);
int double_right_builtin_redirection(t_info *shell, t_command *command);
int pip_builtin_redirection(t_info *shell, t_command *command);
int right_builtin_redirection(t_info *shell, t_command *command);
int left_builtin_redirection(t_info *shell, t_command *command);

/* FORK */
pid_t create_process(void);
/* CHILD */
int child_process(t_info *shell, t_command *command);
int child_redirection(t_info *shell, t_command *command);
int check_path(char *path);
char *get_right_path(char *path, char **path_tab);
/* REDIRECTION */
int child_redirection(t_info *shell, t_command *command);
int double_right_redirection(t_info *shell, t_command *command);
int pip_redirection(t_info *shell, t_command *command);
int right_redirection(t_info *shell, t_command *command);
int left_redirection(t_info *shell, t_command *command);
/* CHILD */
void test_segfault(t_info *shell);
int wait_end_all_exec(t_info *shell);

/* FREE FT */
void *delete_all(t_info *shell);
void delete_command(t_command *command);
t_list *delete_list(t_list *list);
t_builtin **delete_builtin(t_builtin **builtin);
void reset_comma(t_info *shell);
void reset_command(t_info *shell);
void reset_redirect(t_info *shell);

/* HISTORY */
int init_history(void);


/* SH */
int my_sh(t_info *shell);
t_info *prepare_info(char **env);
void print_prompt(void);
int shell(char **env);
/* COMMAND */
int do_execve(t_info *shell, t_command *command);
int command_exec(t_command *command, t_info *shell);
int command_comma(t_info *shell);
int parse_command(t_command *command, t_info *shell);
int command_pip(t_command *command, t_info *shell);
t_list *create_tab_command(t_list *list);
int is_skip_command(t_command *command);
int command_double_sep(t_command *command, t_info *shell);

/* SIGNAL */
int prepare_signal(void);
void sigint_handler(int sig);

/* LIST */
t_list *create_list(void);
t_command *create_command(int len_word, char *str, int i);

int check_sep(char c, char *sep);
t_command *get_separator(t_command *command, char *str, char *sep, int i);
t_list *add_to_list(t_list *list, t_command *command);
t_list *command_to_list(char *str, char *sep);

t_list *command_to_list_double_sep(char *str, char *sep);
int check_sep_double(char c, char d, char *sep);
t_command *get_separator_double(t_command *command, char *str, char *sep, int i);

#endif
