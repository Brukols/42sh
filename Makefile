##
## EPITECH PROJECT, 2018
## 42SH
## File description:
## A simple Makefile to compile
##

NAME	=	42sh

SRC	=	src/main.c	\
		src/builtin/init_builtin.c	\
		src/builtin/is_builtin.c	\
		src/builtin/do_builtin.c	\
		src/alias/add_list_on_alias.c	\
		src/alias/display_list.c		\
		src/alias/remplace_user_line.c	\
		src/alias/local/command_alias.c	\
		src/alias/init_aliases_list.c	\
		src/alias/local/show_one_alias.c	\
		src/alias/local/unalias.c	\
		src/alias/global/alias_glob.c	\
		src/alias/global/fill_list_since_file.c	\
		src/alias/global/recup_path_alias.c	\
		src/alias/global/split_file.c	\
		src/alias/global/verify_file.c	\
		src/builtin/builtin_redirections/builtin_redirection.c	\
		src/builtin/builtin_redirections/double_right_builtin_redirection.c	\
		src/builtin/builtin_redirections/pip_builtin_redirection.c	\
		src/builtin/builtin_redirections/right_builtin_redirection.c	\
		src/builtin/builtin_redirections/left_builtin_redirection.c	\
		src/builtin/echo/my_echo.c	\
		src/builtin/env/my_env/my_env.c	\
		src/builtin/env/my_setenv/add_venv.c	\
		src/builtin/env/my_setenv/create_venv.c	\
		src/builtin/env/my_setenv/my_setenv.c	\
		src/builtin/env/my_setenv/replace_venv.c	\
		src/builtin/env/my_setenv/verif_arg_env.c	\
		src/builtin/env/my_unsetenv/do_unsetenv.c	\
		src/builtin/env/my_unsetenv/exec_unsetenv.c	\
		src/builtin/env/my_unsetenv/my_unsetenv.c	\
		src/builtin/env/is_in_env.c	\
		src/sh/command/globbings.c	\
		src/builtin/env/repair_env.c	\
		src/builtin/env/search_env.c	\
		src/builtin/exit/exit.c	\
		src/builtin/my_cd/change_dir.c	\
		src/builtin/my_cd/change_old_dir.c	\
		src/builtin/my_cd/exec_cd.c	\
		src/builtin/my_cd/my_cd.c	\
		src/builtin/my_cd/update_envcd.c	\
		src/builtin/my_cd/verif_cd.c	\
		src/builtin/repeat/repeat.c	\
		src/builtin/set/my_set/my_set.c	\
		src/builtin/set/my_set/check_alphanumeric_name.c	\
		src/builtin/set/my_set/delete_all_quotation_set.c	\
		src/builtin/set/my_set/delete_quotation_set.c	\
		src/builtin/set/my_set/set_variable.c	\
		src/builtin/set/my_unset/my_unset.c	\
		src/builtin/where/where.c	\
		src/builtin/which/which.c	\
		src/fork/create_process.c	\
		src/fork/child/redirections/child_redirection.c	\
		src/fork/child/redirections/double_right_redirection.c	\
		src/fork/child/redirections/pip_redirection.c	\
		src/fork/child/redirections/right_redirection.c	\
		src/fork/child/redirections/left_redirection.c	\
		src/fork/child/child_process.c	\
		src/fork/child/get_right_path.c	\
		src/fork/wait_child/wait_end_all_exec.c	\
		src/history/add_in_history.c	\
		src/history/check_point_history.c	\
		src/history/find_point_history.c	\
		src/history/history.c	\
		src/history/open_file_history.c	\
		src/history/recup_last_command.c	\
		src/history/recup_path_history.c	\
		src/delete/delete_aliases.c	\
		src/delete/delete_all.c	\
		src/delete/delete_builtin.c	\
		src/delete/delete_list.c	\
		src/delete/reset_comma.c	\
		src/delete/reset_command.c	\
		src/delete/reset_redirect.c	\
		src/delete/delete_var.c	\
		src/list/create_list.c	\
		src/list/add_to_list.c	\
		src/list/create_command.c	\
		src/list/command_to_list/check_sep.c	\
		src/list/command_to_list/command_to_list.c	\
		src/list/command_to_list/get_separator.c	\
		src/list/command_to_list_double/check_sep_double.c	\
		src/list/command_to_list_double/command_to_list_double_sep.c	\
		src/list/command_to_list_double/get_separator_double.c	\
		src/sh/command/command_comma.c	\
		src/sh/command/command_double_sep.c	\
		src/sh/command/command_pip.c	\
		src/sh/command/create_tab_command.c	\
		src/sh/command/command_exec.c	\
		src/sh/command/do_execve.c	\
		src/sh/command/is_skip_command.c	\
		src/sh/command/parse_command.c	\
		src/sh/my_sh.c	\
		src/sh/prepare_info.c	\
		src/sh/print_prompt.c	\
		src/sh/shell.c	\
		src/signal/prepare_signal.c	\
		src/signal/signal_handler.c	\
		src/variable/local_and_env_variable.c	\
		src/variable/change_tab_command.c	\
		src/variable/get_value_name.c		\
		src/variable/replace_the_name.c	\
		src/variable/replace_variable.c	\
		src/variable/get_value_special_variable.c	\
		src/inhibitor/command_in_array.c	\
		src/inhibitor/no_inhibitor.c		\
		src/inhibitor/delete_line_array.c	\
		src/job_control/add_bg_process.c		\
		src/job_control/delete_bg_process.c 	\
		src/job_control/len_bg_process.c	\

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-W -Wall -Wextra -Wshadow -I ./lib/include -I./include

LDFLAGS	=	-lmy -L./lib

CC	=	gcc

all: $(NAME)

$(NAME)	:	$(OBJ)
	$(MAKE) -C ./lib/my
	$(CC) $(OBJ) -o $(NAME) $(LDFLAGS)

tests_run:
	@$(MAKE) --no-print-directory -s -C ./tests

clean:
	$(MAKE) -C ./lib/my clean
	$(MAKE) -C ./tests/ clean
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)
	$(MAKE) -C ./lib/my fclean
	$(MAKE) -C ./tests/ fclean

re:	fclean all

debug : CFLAGS += -g
debug : re

.PHONY: all clean fclean re tests_run debug
