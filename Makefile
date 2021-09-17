# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/15 18:57:29 by lrocigno          #+#    #+#              #
#    Updated: 2021/09/17 19:30:18 by lrocigno         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

define PIPEX
                                                \::::     /::::
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
             
NAME = pipex

CC = clang-13

FLAGS = -Wall -Wextra -Werror -g

EX_RULE = all

LIBS = -L ./libs/libft/ -lft \

INCLUDES = -I ./libs/libft/ \

SRC = pipex.c \

OBJ = $(SRC:%.c=%.o)

SRC_PATH = ./src/

OBJ_PATH = ./obj/

SRC_FULL = $(addprefix $(SRC_PATH), $(SRC))

OBJ_FULL = $(addprefix $(OBJ_PATH), $(OBJ))

all: makelibft objdir $(NAME)
	echo "$$PIPEX"

$(OBJ_FULL): $(SRC_FULL)
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJ_FULL)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ_FULL) $(LIBS)

clean: RULE = clean

clean: makelibft
	rm -rf $(OBJ_PATH)

fclean: RULE = fclean

fclean: makelibft clean
	rm -f $(NAME)

re: fclean all

objdir:
	mkdir -p $(OBJ_PATH)

makelibft:
	make --no-print-directory -C ./libs/libft/ $(RULE)
