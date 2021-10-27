# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lrocigno <lrocigno@student.42.org>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/15 18:57:29 by lrocigno          #+#    #+#              #
#    Updated: 2021/10/27 18:14:04 by lrocigno         ###   ########.fr        #
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

define GREAT_COMMOTION
#include <stdio.h>

int	main(int argc, char **argv)
{
	int	strs;

	strs = 0;
	while (argv[strs] != NULL && strs < argc)
	{
		printf("you argumented: %s\\n", argv[strs]);
		++strs;
	}
	return (0);
}
endef
export GREAT_COMMOTION

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

ERROR =	pipex_error_check_query.c \
		pipex_error_check_argc.c \
		pipex_error_try_fork.c \
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
	rm -f great_commotion.c
	rm -f great_commotion

fclean: clean
	rm -f ./libs/libft/libft.a
	rm -f $(NAME)

re: fclean all

debug:
	echo "$$GREAT_COMMOTION" > great_commotion.c
	$(CC) $(FLAGS) great_commotion.c -o great_commotion

makelibft:
	make -C ./libs/libft/ all

.PHONY: all clean debuig fclean makelibft cdir re
