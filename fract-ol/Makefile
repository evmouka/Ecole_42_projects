NAME = fractol
SRC = fractol.c utils.c events.c init.c math_utils.c render.c
OBJ = $(SRC:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror
MLX_DIR = ./fract-ol/mlx
MLX_LIB = $(MLX_DIR)/libmlx.a
MLX_INC = -I $(MLX_DIR)
MLX = mlx/libmlx_Linux.a
INCLUDES = -Imlx -Ilibft -Ifract-ol/mlx
RM = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	@make -C mlx
	$(CC) $(OBJ) -Lmlx_linux $(MLX) -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re