# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/17 15:39:34 by lfabbro           #+#    #+#              #
#    Updated: 2016/12/05 20:34:02 by lfabbro          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= minishell

SRC_NAME	= main.c ft_init.c ft_parse.c ft_exec.c\
			  ft_env.c ft_setenv.c ft_unsetenv.c ft_chdir.c ft_echo.c\
			  ft_where.c ft_tools.c ft_signal.c ft_exit.c ft_error.c

OBJ_NAME	= $(SRC_NAME:.c=.o)

LIB_NAME	= -lft

SRC_PATH	= ./srcs/
OBJ_PATH	= ./objs/
LIB_PATH	= ./libft/
INC_PATH	= ./includes ./libft/includes ./libft/libft

SRC			= $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ			= $(SRC:.c=.o)
#OBJ			= $(addprefix $(OBJ_PATH),$(OBJ_NAME))
LIB 		= $(addprefix -L, $(LIB_PATH))
INC 		= $(addprefix -I ,$(INC_PATH))

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

RED			= \033[31;44m
GREEN		= \033[32;44m
ENDC		= \033[0m

.PHONY: all lib clean fclean re libfclean libclean

all: lib $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(INC) $(SRC) -o $(NAME) $(LIB) $(LIB_NAME)
	@printf "$(GREEN) Make $(NAME) $(ENDC)\n"

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $< $(INC)

lib:
	@make -C ./libft

clean:
	@printf "$(RED) Removing $(NAME) objects $(ENDC)\n"
	@rm -rfv $(OBJ) $(OBJ_PATH)

fclean: clean libfclean
	@printf "$(RED) Removing $(NAME) executables $(ENDC)\n"
	@rm -fv $(NAME)

libclean:
	@printf "$(RED) Removing $(LIB_PATH) objects $(ENDC)\n"
	@make -C ./libft clean

libfclean:
	@printf "$(RED) Removing $(LIB_PATH) executables $(ENDC)\n"
	@make -C ./libft fclean

re: fclean
	@make all
