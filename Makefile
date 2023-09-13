# VARIABLES
NAME		= so_long
LIBFT_NAME	= libft.a
MLX42_NAME	= libmlx42.a

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
MLX42_FLAGS = -ldl -lglfw -pthread -lm
LIBFT_DIR	= ./libft
MLX42_DIR	= ./MLX42

SRCS		= main.c \
			  # Add other source files here

OBJS		= $(SRCS:.c=.o)

# BUILD TARGETS
all: $(NAME)

# Build the 'libft.a' library
makelibft:
	@make -C $(LIBFT_DIR)
	@cp $(LIBFT_DIR)/$(LIBFT_NAME) .
	@mv $(LIBFT_NAME) $(NAME)

# Build the 'libmlx42.a' library
makemlx42:
	if [ -d ${MLX42_DIR} ]; \
	then git -C ${MLX42_DIR} pull; \
	else git clone git@github.com:codam-coding-college/MLX42.git ${MLX42_DIR}; \
	fi
	cd ${MLX42_DIR} && \
	cmake -B build && \
	cmake --build build -j4

# Use pattern rule for building object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Linking rule for creating the final executable
$(NAME): makelibft makemlx42 $(OBJS)
	$(CC) $(OBJS) ${MLX42_DIR}/build/${MLX42_NAME} -Iinclude $(MLX42_FLAGS) -o $(NAME)



clean:
	@rm -f $(OBJS)
	@cd $(LIBFT_DIR) && make clean

fclean: clean
	@rm -f $(NAME)
	@cd $(LIBFT_DIR) && make fclean

# Rebuild the project from scratch
re: fclean all

.PHONY: all clean fclean re
