/*
** EPITECH PROJECT, 2019
** 42SH
** File description:
** header
*/

#ifndef SHELL_H
#define SHELL_H

#include "my.h"
#include <errno.h>
#include <glob.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <fcntl.h>
#include <time.h>
#include <stdbool.h>
#include "macros.h"

typedef struct s_variable
{
    char *name;
    char **arg;
    struct s_variable *next;
    struct s_variable *prev;
} t_variable;

typedef struct aliase_s
{
    char *new_name;
    char *command;
    struct aliase_s *next;
    struct aliase_s *prev;
} aliase_t;

typedef struct s_info
{
    struct s_builtin **builtin;
    struct aliase_s *aliases;
    struct s_variable *variable;
    char **env;
    FILE *_42rc;
    char *command_line;
    char *path;
    int exit;
    int status;
    pid_t child_pid;
    pid_t gr_pid;
    pid_t *all_bg_process;
    int fd[2];
    int fdd;
    int fd_read;
    int stdin_o;
    int stdou_o;
} t_info;

typedef struct s_list
{
    struct s_command *start;
    int len;
} t_list;

typedef struct s_command
{
    bool bg_process;
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
/*REPEAT*/
long int error_my_repeat(t_command *command);
t_command *create_command_loop(t_command *command);
int my_repeat(t_info *shell, t_command *command);
/* WHICH */
int error_which(t_command *command);
int my_which(t_info *shell, t_command *command);
/* WHERE */
int error_where(t_command *command);
int search_where(t_command *command, char **path_tab,
char *right_path, t_builtin **builtin);
int my_where(t_info *shell, t_command *command);
/* EXIT */
int my_exit(t_info *shell, t_command *command);
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
/* MY_SET */
int my_set(t_info *, t_command *);
int delete_quotation_set(t_command *, int);
int check_alphanumeric_name(t_command *);
int delete_all_quotation_set(t_command *);
int set_variable(t_info *, t_command *, int);
/* MY_UNSET */
int my_unset(t_info *, t_command *);
/* MY_ECHO */
int my_echo(t_info *, t_command *);

/* FORK */
pid_t create_process(void);
/* CHILD */
int child_process(t_info *shell, t_command *command);
int child_redirection(t_info *shell, t_command *command);
int check_path(char *path);
int already_path(char *path);
char *get_right_path(char *path, char **path_tab);
/* REDIRECTION */
int child_redirection(t_info *shell, t_command *command);
int double_right_redirection(t_info *shell, t_command *command);
int pip_redirection(t_info *shell, t_command *command);
int right_redirection(t_info *shell, t_command *command);
int left_redirection(t_info *shell, t_command *command);
/* CHILD */
void test_segfault(t_info *shell, char *error);
int wait_end_all_exec(t_info *shell);

/* DELETE FT */
void *delete_all(t_info *shell);
void delete_command(t_command *command);
t_list *delete_list(t_list *list);
t_builtin **delete_builtin(t_builtin **builtin);
void reset_comma(t_info *shell);
void reset_command(t_info *shell);
void reset_redirect(t_info *shell);
void delete_var(t_variable *var);
void delete_aliases(aliase_t *aliases);

/* HISTORY */
int add_in_history(char *command_line);
char *check_point_history(char *command_line);
int find_point_history(char *command);
int history(t_info *shell, t_command *command);
int open_file_history(void);
char *recup_last_command(void);
char *recup_path_history(void);

/* SH */
int my_sh(t_info *shell);
t_info *prepare_info(int argc, char **argv, char **env);
void print_prompt(t_info *shell);
int shell(int argc, char **argv, char **env);
/* COMMAND */
int do_execve(t_info *shell, t_command *command);
int command_exec(t_command *command, t_info *shell);
int command_comma(t_info *shell);
int parse_command(t_command *command, t_info *shell);
int command_pip(t_command *command, t_info *shell);
t_list *create_tab_command(t_list *list);
int is_skip_command(t_command *command);
char **apply_globbings(char **tab_command);
int command_double_sep(t_command *command, t_info *shell);
void manage_quotation_command_list(char *, int *, int *);
/* SIGNAL */
int prepare_signal(void);
void sigint_handler(int sig);

/* ALIAS */
aliase_t *init_aliases(void);
FILE *alias_is_filled(void);
aliase_t *fill_alias_since_file(aliase_t *alias, FILE *file);
int split_alias_name_and_value(char *full_alias, \
char separator, aliase_t *alias, int *i);
bool bad_alias_line(char *alias);
aliase_t *add_alias_in_list(char *new_name, char *command, aliase_t *alias);
char *split_alias_value(char *all, int i);
char *split_alias_name(char *all, int *i);
t_command *global_alias(t_command *command, t_info *);
t_command *change_command_line(t_info *shell, t_command *command);
aliase_t *local_alias(t_command *command, t_info *shell, bool *);
char **new_line_command(int i, aliase_t *alias, char **tab_command);
char **replace_with_alias(aliase_t *alias, char **tab_command, int i);
void display_alias(aliase_t *);
char *recup_path_alias(void);
bool show_one_alias(char **tab_command, t_info *shell);
aliase_t *unalias(t_command *command, t_info *shell, bool *unalias);

/* LIST */
t_list *create_list(void);
t_command *create_command(int len_word, char *str, int i);

int check_sep(char c, char *sep);
t_command *get_separator(t_command *command, char *str, char *sep, int i);
t_list *add_to_list(t_list *list, t_command *command);
t_list *command_to_list(char *str, char *sep);

t_list *command_to_list_double_sep(char *str, char *sep);
int check_sep_double(char *c, int pos, char *sep);
t_command *get_separator_double(t_command *command, char *str,
char *sep, int i);
/* VARIABLE */
int local_and_env_variable(t_command *, t_info *);
int replace_variable(t_command *, t_info *, int, int);
int replace_the_name(t_command *, char **, int);
int parse_command(t_command *, t_info *);
char **get_value_name(t_info *, char *);
int change_tab_command(t_command *, char **, int, int);
bool is_alphanumeric(char);
char **get_value_special_variable(t_info *, char *);
char **get_value_in_env(t_info *shell, char *name);
char *get_name_variable(t_command *cmd, int i, int a);

/* INHIBITOR */
char **command_in_array(char *str, char *sep);
char *delete_one_chara(char *str, int pos);
bool no_inhibitor(char *str, int i);
char **delete_line_array(char **arr, int i);

/* JOB_CONTROL */
pid_t *add_bg_process(pid_t *, pid_t);
int len_bg_process(pid_t *);
pid_t *delete_bg_process(pid_t *, pid_t);

#endif
