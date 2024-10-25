# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thkumara <thkumara@student.42singapor      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/02 13:37:26 by thkumara          #+#    #+#              #
#    Updated: 2024/10/02 13:37:31 by thkumara         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME := so_long

CC := gcc 

CFLAGS := -g -Wall -Wextra -Werror -Iheaders/

SOURCE := source/*.c
GETNEXTLINE := getnextline/*.c
PRINTF := libftprintf/*.c
LIBRARY := -Lminilibx libmlx.a -lXext -lX11 -lm
MINILIBX := minilibx-linux/

all:
	make -C $(MINILIBX)
	$(CC) $(CFLAGS) $(SOURCE) $(GETNEXTLINE) $(PRINTF) $(LIBRARY) -o $(NAME)

clean:

fclean: clean
		make clean -C $(MINILIBX)
		rm -rf $(NAME)

re: fclean all
