# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jvoor <jvoor@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/23 19:36:31 by jvoor             #+#    #+#              #
#    Updated: 2019/12/10 17:43:40 by jvoor            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

#LID = ./libft/
#MLX = ./mlx/

#HEAD = fractol.h

SRC = main.c \
		keys.c \
		fractols.c \
		exit.c \
		draw.c \
		init.c

OBJ = $(SRC:.c=.o)

SRCDIR = src

L_LIB = libft/libft.a

I_LIB = -I libft 

L_MLX = -L /usr/local/include

I_MLX = -I /usr/local/include

I_FDF = -I . 

CFL = -Wall -Wextra -Werror

MLXFL = -lmlx -framework OpenGL -framework AppKit

vpath %.c $(SRCDIR)

.PHONY: all dir clean fclean re

all: lib $(NAME)

$(NAME): $(OBJ)
	@gcc $(CFL) $^ $(L_LIB) $(L_MLX) $(I_FDF) $(I_LIB) $(I_MLX) $(MLXFL) -o $(NAME)
	@echo "\ncompiling fractol\n"

$(OBJ): $(SRC)
	@gcc $(CFL) -c $^ $(I_FDF) $(I_LIB) $(I_MLX)

lib:
	@make -C libft/

clean:
	@make -C libft/ clean

fclean:
	@make -C libft fclean
	@rm -f $(NAME)
	@rm -f $(OBJ)

re: fclean all