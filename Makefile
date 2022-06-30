# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anniegraetz <anniegraetz@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/26 16:07:05 by anniegraetz       #+#    #+#              #
#    Updated: 2022/06/23 16:17:31 by anniegraetz      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iheaderfiles/ 

SRC = srcs/*.c
GNL = gnl/*.c
LIB = -L minilibx -lmlx -framework OpenGL -framework AppKit
MLX := minilibx/

all:
	make -C $(MLX)
	$(CC) $(CFLAGS) $(SRC) $(GNL) $(LIB) -o $(NAME)

r:
	make
	clear
	./$(NAME) maps/map3.ber

clean:

fclean: clean
	make clean -C $(MLX)
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re