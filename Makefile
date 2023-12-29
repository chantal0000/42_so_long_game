# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chbuerge <chbuerge@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/29 13:57:13 by chbuerge          #+#    #+#              #
#    Updated: 2023/12/29 18:13:17 by chbuerge         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
LIBFT_NAME = libft/libft.a

CFLAGS = -Wextra -Wall -Werror
MINILIBX_FLAGS =

CC = cc
VALGRIND = @valgrind --leak-check=full
REMOVE = rm -f
LIBFT_DIR = ./libft


SRC = main.c

OBJS = ${SRC:.c=.o}

all: $(NAME)

$(NAME): $(LIBFT_NAME) $(OBJS)
	$(CC)	$(CFLAGS)	$(OBJS)	$(LIBFT_NAME)	-o	$(NAME)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
$(LIBFT_NAME):
	cd libft && make
clean:
	rm -f $(OBJS)
	cd libft && make clean

fclean: clean
	rm -f $(NAME)
	cd libft && make fclean

re : fclean all
