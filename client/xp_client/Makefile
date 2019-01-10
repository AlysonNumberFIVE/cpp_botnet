# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: angonyam <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/12 06:34:00 by angonyam          #+#    #+#              #
#    Updated: 2017/09/18 15:38:55 by angonyam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC=builtins/cd.c builtins/echo.c builtins/setenv.c \
    builtins/cd_handle_access.c builtins/env.c builtins/unsetenv.c \
    builtins/exit.c builtins/echo_support.c\
    minishell.c\
	misc/array_len.c misc/arraydup.c misc/free_2d_array.c \
    misc/putarray.c misc/get_line.c misc/wordcount.c misc/ft_isspace.c\
    misc/ft_delarray.c misc/tabspace.c\
    processes/process.c processes/signals.c\
	parsing/arg_commands.c parsing/no_arg_commands.c \
    parsing/args_commands_2.c\
	libft/ft_isalnum.c libft/ft_putchar.c libft/ft_putendl.c\
    libft/ft_putstr.c libft/ft_strcat.c libft/ft_strchr.c libft/ft_strcmp.c\
    libft/ft_strcpy.c libft/ft_strjoin.c libft/ft_strlen.c\
    libft/ft_strncmp.c libft/ft_strsplit.c libft/ft_memalloc.c\
    libft/ft_strnew.c libft/ft_bzero.c libft/ft_memset.c\
    libft/ft_atoi.c libft/ft_itoa.c libft/ft_abs.c libft/ft_strdel.c\
    libft/ft_strdup.c libft/ft_putnbr.c

OBJ=$(SRC:%.c=%.o)

FLAGS=-Wall -Werror -Wextra -g -g3

all:
	@make -C libft/
	@gcc -o minishell libft.a $(FLAGS) $(SRC)

clean:
	@rm -f $(OBJ)

fclean:
	@rm -f libft.a


