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
PROJECT = filler
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

GREEN = \033[32m
CYAN = \033[36m
NO_COLOR=\033[0m

PREP_STR = $(CYAN)Preparing $(PROJECT)...$(NO_COLOR)
CLEANO_STR = $(CYAN)Cleaning object files...$(NO_COLOR)
CLEANB_STR = $(CYAN)Cleaning binary files...$(NO_COLOR)
OK_STR = $(GREEN)[OK]$(NO_COLOR)

LIB = libft/
MLX = mlx/
INCL = -I $(LIB)inc/ -I inc/
LIBRARIES = $(LIB)libft.a $(MLX)libmlx.a
FRAMEWORK = -framework OpenGL -framework AppKit
C_FILES = $(addprefix src/, $(addsuffix .c, $(FUNCTIONS)))
CC = gcc
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):

	@echo "$(PREP_STR)"
	@$(MAKE) -C $(LIB)
	$(CC) $(FLAGS) $(INCL) $(C_FILES) $(LIBRARIES) -o $(NAME)
	@echo "$(PROJECT) Complete! $(NAME)...$(OK_STR)"

clean:
	$(MAKE) clean -C $(LIB)

fclean:	clean
	$(MAKE) fclean -C $(LIB)
	@rm -f $(NAME)

re: fclean all
