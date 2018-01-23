#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmontoya <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/22 20:24:48 by dmontoya          #+#    #+#              #
#    Updated: 2018/01/22 19:45:58 by dmontoya         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = dmontoya.filler

FUNCTIONS =	placepiece \
			tactic \
			tactic_2 \
			filler \
			gamedata \
			utilities \
			inspectgameboardborders \
			gameborders \
			playersposition \
			gamemap

LIB = libft/
INCL = $(LIB)libft.a mlx/libmlx.a
FRAMEWORK = -framework OpenGL -framework AppKit
C_FILES = $(addsuffix .c, $(FUNCTIONS))
CC = gcc
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):

	$(MAKE) -C $(LIB)
	$(CC) $(FLAGS) $(C_FILES) $(INCL) $(FRAMEWORK) -o $(NAME)

clean:
	rm -rf $(OBJ_FILES) *~
	$(MAKE) clean -C $(LIB)

fclean:	clean
	$(MAKE) fclean -C $(LIB)
	rm -rf $(NAME)

re: fclean all
