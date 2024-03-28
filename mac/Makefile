# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bautrodr <bautrodr@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/14 19:18:14 by bautrodr          #+#    #+#              #
#    Updated: 2023/12/20 17:24:52 by bautrodr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RESET = \033[0m
BOLD = \033[1m
RED = \033[91m
GREEN = \033[92m
YELLOW = \033[93m
CYAN = \033[96m

NAME = so_long
SRCS = ./src/main.c \
	   ./src/free.c \
	   ./src/key.c \
	   ./src/check_map.c \
	   ./src/check_path.c \
	   ./src/map.c \
	   ./src/standard_img.c \
	   ./src/more_checks.c \
	   ./src/player_movement.c \
	   ./src/print_error.c \
	   ./src/print_player.c

OBJS = $(SRCS:.c=.o)
DEPS = $(addsuffix .d, $(basename $(SRCS)))

GET_NEXT_LINE = get_next_line/get_next_line.c \
				get_next_line/get_next_line_utils.c

INCLUDES_DIR = ./includes
INCLUDE_LIBFT = ./libft/libft.a
LIBFT_DIR = ./libft
SO_LONG_LIB = ./includes/so_long.h
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

.c.o:
	@echo "$(YELLOW)Compiling objects$(RESET)"
	$(CC) $(CFLAGS) -c $< -o $@

UNAME = $(shell uname -s)

ifeq ($(UNAME), Linux)
	MLX_FLAGS = -lXext -lX11 -lm -lbsd
	MLX_PATH = ./mlx/mlx_linux
	MLX_LIB_PATH = $(MLX_PATH)/libmlx.a
else
	MLX_FLAGS = -framework OpenGL -framework Appkit -l z
	MLX_PATH = ./mlx/mlx_mac
	MLX_LIB_PATH = $(MLX_PATH)/libmlx.a
endif

FLAGS = -I $(INCLUDES_DIR) -I $(MLX_PATH) $(CFLAGS)

-include $(DEPS)

$(NAME) : Makefile $(SO_LONG_LIB) $(OBJS) $(LIBFT_DIR)/libft.h
	@make -C $(MLX_PATH) all
	@make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(FLAGS) $(OBJS) $(INCLUDE_LIBFT) $(GET_NEXT_LINE) $(MLX_LIB_PATH) $(MLX_FLAGS) -o $(NAME)
	@echo "$(GREEN)$(BOLD) $(NAME)$(RESET) $(GREEN)built successfully$(RESET)"

clean:
	@echo "$(YELLOW)Cleaning object files$(RESET)"
	@make -C $(MLX_PATH) clean
	@make -C $(LIBFT_DIR) clean
	rm -f $(OBJS)
	@echo "$(GREEN)Object files cleaned$(RESET)"

fclean: clean
	@echo "$(YELLOW)Cleaning executables$(RESET)"
	@make -C $(LIBFT_DIR) fclean
	rm -f $(NAME)
	@echo "$(GREEN)Executables cleaned$(RESET)"

re: fclean all

.PHONY: all clean fclean re
