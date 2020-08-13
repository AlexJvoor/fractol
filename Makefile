# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jvoor <jvoor@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/08 20:09:38 by jvoor             #+#    #+#              #
#    Updated: 2020/02/03 11:50:57 by jvoor            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

FLAGS = -c -Wall -Wextra -Werror

MLXFLAGS = -lmlx -framework OpenGL -framework OpenCL -framework AppKit -Wall -Wextra -Werror

SRCS = main.c \
		frl_init.c \
		frl_keys.c \
		frl_win.c \
		frl_draw.c \
		frl_cl_prep.c \
		frl_norm_file01.c

INCLUDES = $(addprefix -I, ./includes)

LIBFT = libft/libft.a

DIR_O = objs

DIR_S = srcs

OBJS = $(addprefix $(DIR_O)/,$(SRCS:.c=.o))

all: $(NAME)

$(NAME): $(DIR_O) $(OBJS)
	@make -C ./libft
	gcc -I include $(OBJS) $(LIBFT) $(MLXFLAGS) -g -o $(NAME)

$(DIR_O):
	mkdir -p $(DIR_O)

$(DIR_O)/%.o: $(DIR_S)/%.c
	gcc $(FLAGS) $(INCLUDES) -o $@ $<

clean:
	@/bin/rm -rf $(DIR_O)
	@make clean --directory ./libft

fclean: clean
	@/bin/rm -f $(NAME)
	@make fclean --directory ./libft

re: fclean all

.PHONY: all dir clean fclean re
