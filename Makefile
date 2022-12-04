name = minishell

src = env/env_list.c execute/ex_cmd.c execute/redir.c lexer/list.c parsing/parser.c utils/ft_atoi.c \
	utils/ft_realloc.c utils/get_line.c env/env_search.c execute/execute.c lexer/lexer.c parsing/core.c \
	parsing/redir_utils.c utils/ft_calloc.c utils/ft_split.c utils/string.c env/env_utils.c execute/find.c \
	lexer/lexer_utils.c parsing/par_utils.c parsing/tree.c utils/ft_itoa.c utils/string_utils.c \
	clean_up.c error_files.c main.c syntax.c execute/ex_built/echo_utils.c execute/ex_built/exp_utils1.c \
	execute/ex_built/exp_utils2.c execute/ex_built/ft_cd.c execute/ex_built/ft_echo.c execute/ex_built/ft_env.c execute/ex_built/ft_exit.c \
	execute/ex_built/ft_export.c  execute/ex_built/ft_pwd.c execute/ex_built/ft_unset.c main_utils.c sigs.c


obj = $(src:.c=.o)

flags = -L/goinfre/youssama/.brew/opt/readline/lib -I/goinfre/youssama/.brew/opt/readline/include -lreadline -Wall -Wextra -Werror

hd = minishell.h env.h

all: $(name)

$(name): $(src) $(hd)
	cc $(flags) $(src) -o $(name)

%.o:%.c
	cc $(flags) -c $< -o $@

clean:
	rm -rf $(obj)

fclean: clean
	rm -rf $(name)

re: fclean all