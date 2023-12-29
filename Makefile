NAME = so_long
SRC =
GNL_SRC =
PRINTF_SRC =
OBJ := $(SRC:%.c=%.o)
GNL_OBJ := $(GNL_SRC:%.c=%.o)
PRINTF_OBJ := $(PRINTF_SRC:%.c=%.o)
CC = gcc
CCFLAGS = -Wextra -Wall -Werror
all: $(NAME)
$(NAME): $(OBJ) $(GNL_OBJ) $(PRINTF_OBJ)
    $(CC) $(CCFLAGS) $^ -lmlx   -lXext  -lX11   -Lmlx   -framework OpenGL -framework AppKit -o $(NAME)
%.o: %.c
    gcc $(CCFLAGS) -Imlx -Iincludes -c $< -o $@
clean:
    rm -f $(OBJ) $(GNL_OBJ) $(PRINTF_OBJ)
fclean: clean
    make clean -C mlx/
    rm -f $(NAME)
re : fclean all
