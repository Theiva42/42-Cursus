# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thkumara <thkumara@student.42singapor      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/10 12:03:38 by thkumara          #+#    #+#              #
#    Updated: 2024/06/10 12:03:44 by thkumara         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME	= libftprintf.a

SRCS	= ft_printf.c\
		  ft_inttohex.c\
		  ft_putchar.c\
		  ft_putnbr.c\
		  ft_putptr.c\
		  ft_putstr.c\
		  ft_putunsigned.c\
		  ft_strchr.c\

OBJS	= $(SRCS:%.c=%.o)

FLAGS	= -Wall -Wextra -Werror 

$(NAME):
		gcc $(FLAGS) -c $(SRCS) -I ./
		ar rc $(NAME) $(OBJS)

all : $(NAME)

clean : 
		rm -f $(OBJS)

fclean : clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
