SRCS	= main.c ft_argvsplit.c ft_splitutils.c get_those_quotes.c parse_machine.c \
		builtins.c export_funct.c builtins_functions.c minishell_utils.c pipex.c \
		dup_fds.c cd_funct.c open_and_file_error.c dollarsign.c dollarutils.c signals.c \
		get_those_pipes.c ft_add_history.c minishell_utils2.c ft_echo.c \
		double_pipes_and_files.c

OBJS	= ${SRCS:.c=.o}

NAME	= minishell

CC	= gcc

RM	= rm -f

CFLAGS	= -Wall -Wextra -Werror

LIBFT = libft/libft.a

PATHLIB = libft/

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${LIBFT} ${OBJS}
				${CC} ${CFLAGS} ${LIBFT} ${OBJS} -lreadline -L /Users/$(USER)/.brew/opt/readline/lib -I /Users/$(USER)/.brew/opt/readline/include -o ${NAME}

${LIBFT}:
			@make -C ${PATHLIB}

all:		${NAME}

clean:
				@make clean -C ${PATHLIB}
				${RM} ${OBJS} ${OBJB}

fclean: 	clean
				@make fclean -C ${PATHLIB}
				${RM} ${NAME}

re: 		fclean all

.PHONY:		all clean fclean re
