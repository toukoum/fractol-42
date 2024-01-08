NAME = fractol

OS := $(shell uname)
CC = cc
CFLAGS = -Wall -Werror -Wextra

ifeq ($(OS), Darwin)
	MLX_PATH = ./mlx-opengl
	MLX_FLAGS = -I $(MLX_PATH) -L $(MLX_PATH) -lmlx -framework OpenGL -framework AppKit
	MLX_LIB = mlx-opengl/libmlx.a
else
	MLX_PATH = ./mlx-linux
	MLX_FLAGS = -I/usr/include -Imlx-linux -lXext -lX11 -lm -lz -Lmlx-linux -lmlx -L/usr/lib
	MLX_LIB = mlx_opengl/libmlx.a
endif

MAIN = srcs/main.c
SRCS = $(wildcard srcs/*.c)
DEPS = $(wildcard includes/*.h)

LIBFT_DIR = libft/
LIBFT_LIB = libft/libft.a

all : $(NAME)

$(NAME) : $(LIBFT_LIB) $(SRCS) $(DEPS) $(MLX_LIB)
	$(CC) $(CFLAGS) $(SRCS) $(LIBFT_LIB) $(MLX_FLAGS) -o $(NAME)

$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT_DIR)

$(MLX_LIB):
	$(MAKE) -C $(MLX_PATH)

clean:
	make clean -C $(LIBFT_DIR)
	make clean -C $(MLX_PATH)

fclean:
	make fclean -C $(LIBFT_DIR)
	rm -rf $(NAME) $(NAME_BONUS)

re: fclean all

t : all 
	@echo "execution de fractol..."
	@./fractol

.PHONY: all clean fclean re