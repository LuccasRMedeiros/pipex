# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/15 18:57:29 by lrocigno          #+#    #+#              #
#    Updated: 2021/10/28 11:33:12 by lrocigno         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

define PIPEX
                                                \ + +     / + +
                                                 \++++   /++++
          _____     __     _____     _______      \+x+x/x+x+
         /  _  \   /  |   /  _  \   /  _____|      \+x+x+x+
        /  /_| |  /  /   /  /_| |  /  /__         /xxxxxx
       /  _____/ /  /   /  _____/ /  ___/       /xxxx\xxxx
      /  /      /  /   /  /      /  /          /xXxX  \XxXx
     /  /      /  /   /  /      /  /_____    /XxXx     \XxXx
    |__/      |__/   |__/      |________/   /XXXX       \XXXX

 - Ready to pipe!
endef
export PIPEX

NAME = pipex

CC = clang-13

FLAGS = -Wall -Wextra -Werror -g -fsanitize=address

EX_RULE = all

LIBS = -L ./libs/libft/ -lft \

INCLUDES = -I ./libs/libft/ \
		   -I ./src/ \
		   -I ./error/ \
		   -I ./utils/ \

BASE =	new_query.c \
		del_query.c \

ERROR =	pipex_error_try_fork.c \
		pipex_error_try_execve.c \
		pipex_error_try_open.c \

UTILS =	pipex_utils_parse_cmd.c \
		pipex_utils_redir.c \
		pipex_utils_set_cmds.c \

SRC = $(BASE) $(ERROR) $(UTILS)

OBJ = $(SRC:%.c=%.o)

SRC_FULL = $(addprefix ./src/, $(BASE)) \
		   $(addprefix ./error/, $(ERROR)) \
		   $(addprefix ./utils/, $(UTILS)) \

all: makelibft $(NAME)
	echo "$$PIPEX"

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(INCLUDES) pipex.c -o $(NAME) $(OBJ) $(LIBS)

$(OBJ): $(SRC_FULL)
	$(CC) $(FLAGS) $(INCLUDES) -c $(SRC_FULL)

clean:
	make -C ./libs/libft/ clean
	rm -f *.o

fclean: clean
	rm -f ./libs/libft/libft.a
	rm -f $(NAME)

re: fclean all

makelibft:
	make -C ./libs/libft/ all

.PHONY: all clean fclean makelibft re
