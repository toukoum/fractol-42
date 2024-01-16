NAME = fractol

CC = cc
CFLAGS = -Wall -Werror -Wextra -g -O3
MAKE_FLAGS = -s -C

MLX_PATH = ./mlx-linux
MLX_FLAGS = -I/usr/include -Imlx-linux -lXext -lX11 -lm -lz -Lmlx-linux -lmlx -L/usr/lib
MLX_LIB = mlx_opengl/libmlx.a

RED=\033[0;31m
ROSE=\033[0;95m
GREEN=\033[0;32m
NC=\033[0m
YELLOW=\033[0;33m
CYAN=\033[0;34m 

SRCS = atod.c color_utils.c event.c init.c maths.c utils.c color.c display_help.c exit.c main.c render.c
SRCS := $(addprefix srcs/, $(SRCS))

DEPS = includes/fractol.h

LIBFT_DIR = libft/
LIBFT_LIB = libft/libft.a

all : $(NAME)

$(NAME) : $(LIBFT_LIB) $(SRCS) $(DEPS) $(MLX_LIB)
	@echo "$(GREEN)Creating fractol...$(NC)"
	@$(CC) $(CFLAGS) $(SRCS) $(LIBFT_LIB) $(MLX_FLAGS) -o $(NAME)
	@echo "$(CYAN) ====== DONE ! ======\n$(NC)"


$(LIBFT_LIB):
	@echo "$(ROSE)Creating library libft...$(NC)"
	@$(MAKE) $(MAKE_FLAGS) $(LIBFT_DIR)

$(MLX_LIB):
	@echo "$(YELLOW)Creating library minilibx...$(NC)"
	@$(MAKE) $(MAKE_FLAGS) $(MLX_PATH) > /dev/null 2>&1

clean:
	@echo "\n$(RED)Cleaning project Fractol...$(NC)"
	@make clean $(MAKE_FLAGS) $(LIBFT_DIR) > /dev/null
	@make clean $(MAKE_FLAGS) $(MLX_PATH) > /dev/null
	@echo "$(CYAN) ====== DONE ! ======\n$(NC)"


fclean:
	@echo "\n$(RED)Cleaning project Fractol...$(NC)"
	@make fclean $(MAKE_FLAGS) $(LIBFT_DIR) > /dev/null
	@make clean $(MAKE_FLAGS) $(MLX_PATH) > /dev/null
	@rm -rf $(NAME) $(NAME_BONUS)
	@echo "$(CYAN) ====== DONE ! ======\n$(NC)"

re: fclean all

t : all 
	@echo "execution de fractol..."
	@./fractol

.PHONY: all clean fclean re