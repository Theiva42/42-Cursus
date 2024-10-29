# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thkumara <thkumara@student.42singapor      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/21 14:24:28 by thkumara          #+#    #+#              #
#    Updated: 2024/10/21 14:30:22 by thkumara         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME := push_swap

CC := cc

CFLAGS := -g -Wall -Wextra -Werror

SOURCE := source/*.c
PRINTF := libftprintf/*.c
LIBFT := libft/*.c

$(NAME): $(SOURCE) $(PRINTF) $(LIBFT)
		$(CC) $(CFLAGS) $(SOURCE) $(PRINTF) $(LIBFT) -o $(NAME) -I ./

all : $(NAME)

clean : 
		rm -f $(NAME)

fclean : clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
