NAME = fractol
SRC = math.c \
	  rendering.c \
	  fractal_utils.c \
	  fractol.c \
	  events.c
OBJ = $(SRC:.c=.o)
CC = cc
MLX_DIR = ./minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx.a
MLX_INC = $(MLX_DIR)
CFLAGS = -Wall -Wextra -Werror -I$(MLX_INC) -I./

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(CFLAGS) $(MLX_LIB) -lXext -lX11 -lm
	@echo "Mandatory Part : Compilation done."


%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
