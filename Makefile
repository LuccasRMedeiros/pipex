# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lrocigno <lrocigno@student.42.org>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/15 18:57:29 by lrocigno          #+#    #+#              #
#    Updated: 2021/10/09 01:27:29 by lrocigno         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

define PIPEX
                                                \ - -     / - -
                                                 \::::   /::::
          _____     __     _____     _______      \+:+:/:+:+
         /  _  \   /  |   /  _  \   /  _____|      \:+:+:+:
        /  /_| |  /  /   /  /_| |  /  /__         /++++++
       /  _____/ /  /   /  _____/ /  ___/       /++++\++++
      /  /      /  /   /  /      /  /          /+#+#  \+#+#
     /  /      /  /   /  /      /  /_____    /#+#+     \#+#+
    |__/      |__/   |__/      |________/   /####       \####

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

FLAGS = -Wall -Wextra -Werror -g

EX_RULE = all

LIBS = -L ./libs/libft/ -lft \

INCLUDES = -I ./libs/libft/ \

SRC_DIR = ./src/

OBJ_DIR = ./obj/

SRC = pipex_utils/pipex_utils_parse_cmd.c

OBJ = $(SRC:%.c=%.o)

SRC_FULL = $(addprefix $(SRC_DIR), $(SRC))

OBJ_FULL = $(addprefix $(OBJ_DIR), $(OBJ))

all: makelibft cdir $(NAME)
	echo "$$PIPEX"

$(NAME): $(OBJ_FULL)
	$(CC) $(FLAGS) $(INCLUDES) ./src/pipex.c -o $(NAME) $(OBJ_FULL) $(LIBS)

$(OBJ_FULL): $(SRC_FULL)
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

clean:
	make -C ./libs/libft/ clean
	rm -rf $(OBJ_PATH)
	rm -f great_commotion.c
	rm -f great_commotion

fclean: clean
	rm -f ./libs/libft/libft.a
	rm -f $(NAME)

re: fclean all

debug:
	echo "$$GREAT_COMMOTION" > great_commotion.c
	$(CC) $(FLAGS) great_commotion.c -o great_commotion

cdir:
	mkdir -p $(OBJ_DIR)
	mkdir -p $(OBJ_DIR)pipex_utils/

makelibft:
	make -C ./libs/libft/ all

.PHONY: all clean debuig fclean makelibft cdir re
