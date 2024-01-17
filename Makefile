# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chbuerge <chbuerge@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/29 13:57:13 by chbuerge          #+#    #+#              #
#    Updated: 2024/01/17 10:01:00 by chbuerge         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
LIBFT_NAME = libft/libft.a
MLX_LIB = mlx/
CFLAGS = -Wextra -Wall -Werror -g
MINILIBX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11

CC = cc
LIBFT_DIR = ./libft


SRC = main.c \
	map_functions/read_and_process_map.c \
	map_functions/map_check.c \
	map_functions/map_init.c \
	map_functions/check_map_solvable.c \
	so_long_utils.c \
	game_setup.c \
	game_play.c \
	free.c

OBJS = ${SRC:.c=.o}

all: $(NAME)

$(NAME): $(LIBFT_NAME) $(OBJS)
	@if [ ! -d "mlx" ]; then \
	git clone https://github.com/42Paris/minilibx-linux.git mlx; \
	fi
	@make -C $(MLX_LIB)
	$(CC) $(CFLAGS) $(OBJS) $(MINILIBX_FLAGS) $(LIBFT_NAME) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(LIBFT_NAME):
	cd libft && make

clean:
	rm -f $(OBJS)
	cd libft && make clean

fclean: clean
	@if [ -d "mlx" ]; then \
	make clean -C mlx/; \
	fi
	rm -f $(NAME)
	cd libft && make fclean

re : fclean all

.PHONY: all clean fclean re
