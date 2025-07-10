# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jissa <jissa@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/03 09:43:54 by jissa             #+#    #+#              #
#    Updated: 2025/07/10 12:59:32 by jissa            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror

MLX_DIR = minilibx-linux
MLX_LIB = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm
MLX_INC = -I$(MLX_DIR)

GNL_DIR = GNL

PRINTF_DIR = printf
PRINTF_LIB = $(PRINTF_DIR)/libftprintf.a
PRINTF_INC = -I$(PRINTF_DIR)/includes -I$(PRINTF_DIR)/libft

SRCS = so_long.c map_check.c free.c flood_fill.c creating_arr.c \
	game.c game2.c so_long_utils.c \
	$(GNL_DIR)/get_next_line.c $(GNL_DIR)/get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(PRINTF_DIR)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_INC) $(MLX_LIB) $(PRINTF_LIB) $(PRINTF_INC) -o $(NAME)

clean:
	rm -f $(OBJS)
	make -C $(PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(PRINTF_DIR) fclean
	
re: fclean all

.PHONY: all clean fclean re

