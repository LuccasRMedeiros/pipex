# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lrocigno <lrocigno@student.42.org>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/15 18:57:29 by lrocigno          #+#    #+#              #
#    Updated: 2021/10/03 17:03:39 by lrocigno         ###   ########.fr        #
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

	while (strs = 0; argv[strs] != NULL && strs < argc; ++strs)
		printf("you argumented: %s\\n", argv[strs]);
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

SRC =

OBJ = $(SRC:%.c=%.o)

SRC_PATH = ./src/

OBJ_PATH = ./obj/

SRC_FULL = $(addprefix $(SRC_PATH), $(SRC))

OBJ_FULL = $(addprefix $(OBJ_PATH), $(OBJ))

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
	rm -rf $(BIN_PATH)

re: fclean all

debug:
	echo "$$GREAT_COMMOTION" > great_commotion.c
	$(CC) $(FLAGS) great_commotion.c -o great_commotion

cdir:
	mkdir -p $(OBJ_PATH)

makelibft:
	make -C ./libs/libft/ all

.PHONY: all clean debuig fclean makelibft cdir re
