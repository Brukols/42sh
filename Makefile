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
		src/builtin/builtin_redirections/builtin_redirection.c	\
		src/builtin/builtin_redirections/double_right_builtin_redirection.c	\
		src/builtin/builtin_redirections/pip_builtin_redirection.c	\
		src/builtin/builtin_redirections/right_builtin_redirection.c	\
		src/builtin/builtin_redirections/left_builtin_redirection.c	\
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
		src/builtin/env/repair_env.c	\
		src/builtin/env/search_env.c	\
		src/builtin/my_cd/change_dir.c	\
		src/builtin/my_cd/change_old_dir.c	\
		src/builtin/my_cd/exec_cd.c	\
		src/builtin/my_cd/my_cd.c	\
		src/builtin/my_cd/update_envcd.c	\
		src/builtin/my_cd/verif_cd.c	\
		src/builtin/set/my_set.c	\
		src/builtin/set/my_unset.c	\
		src/fork/create_process.c	\
		src/fork/child/redirections/child_redirection.c	\
		src/fork/child/redirections/double_right_redirection.c	\
		src/fork/child/redirections/pip_redirection.c	\
		src/fork/child/redirections/right_redirection.c	\
		src/fork/child/redirections/left_redirection.c	\
		src/fork/child/child_process.c	\
		src/fork/child/get_right_path.c	\
		src/fork/wait_child/wait_end_all_exec.c	\
		src/history/init_history.c	\
		src/free/delete_all.c	\
		src/free/delete_builtin.c	\
		src/free/delete_list.c	\
		src/free/reset_comma.c	\
		src/free/reset_command.c	\
		src/free/reset_redirect.c	\
		src/list/add_to_list.c	\
		src/list/check_sep.c	\
		src/list/command_to_list.c	\
		src/list/create_command.c	\
		src/list/create_list.c	\
		src/list/get_separator.c	\
		src/sh/command/command_comma.c	\
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
		src/variable/cmd_has_a_value.c		\

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-W -Wall -Wextra -Wshadow -I ./lib/include -I./include

LDFLAGS	=	-lmy -L./lib

CC	=	gcc

all: $(NAME)

$(NAME)	:	$(OBJ)
	$(MAKE) -C ./lib/my
	$(CC) $(OBJ) -o $(NAME) $(LDFLAGS)

tests_run:
	$(MAKE) -C ./tests

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

.PHONY: all clean fclean re tests_run
