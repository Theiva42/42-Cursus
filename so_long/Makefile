# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thkumara <thkumara@student.42singapor      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/24 17:30:19 by thkumara          #+#    #+#              #
#    Updated: 2024/09/24 18:11:31 by thkumara         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME	= so_long

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

MLX_PATH = mlx/

MLX_LIB = $(MLX_PATH)libmlx.a

MLX_FLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit

LIBFT_PATH = libft/

LIBFT_LIB = $(LIBFT_PATH)libft.a

SRCS	= 

OBJS	= $(SRCS:.c=.o)

all: subsystems $(NAME)

%.o : %.c
		$(CC) $(CFLAGS) -Imlx -c -o $@ $<

subsystems:
		@make -C $(MLX_PATH) all
		@make -C $(LIBFT_PATH) all

$(NAME): $(OBJS)
		   $(CC) $(CFLAGS) $(MLX_FLAGS) $(OBJECTS) $(MLX_LIB)$(LIBFT_LIB) -o $(NAME)

clean :
		make -C $(MLX_PATH) clean
		make -c $(LIBFT_PATH) clean
		rm -f $(OBJS)

fclean : clean
        make -C $(MLX_PATH) fclean
        make -c $(LIBFT_PATH) fclean
		rm -f $(NAME)

re: fclean all

norm:
		norminette libft 

.PHONY: all clean fclean re norm
