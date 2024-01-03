# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chbuerge <chbuerge@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/29 13:57:13 by chbuerge          #+#    #+#              #
#    Updated: 2024/01/03 10:57:17 by chbuerge         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
LIBFT_NAME = libft/libft.a

CFLAGS = -Wextra -Wall -g
MINILIBX_FLAGS = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

CC = cc
#VALGRIND = @valgrind --leak-check=full
REMOVE = rm -f
LIBFT_DIR = ./libft


SRC = main.c \
		check_map.c \
		so_long_utils.c \
		game.c

OBJS = ${SRC:.c=.o}

all: $(NAME)

$(NAME): $(LIBFT_NAME) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MINILIBX_FLAGS) $(LIBFT_NAME) -o $(NAME)
%.o: %.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@
$(LIBFT_NAME):
	cd libft && make
clean:
	rm -f $(OBJS)
	cd libft && make clean

fclean: clean
	rm -f $(NAME)
	cd libft && make fclean

re : fclean all
