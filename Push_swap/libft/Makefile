# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thkumara <thkumara@student.42singapor      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/28 12:27:04 by thkumara          #+#    #+#              #
#    Updated: 2024/05/28 14:18:05 by thkumara         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME		= libft.a

SRCS		= 	  ft_strlen.c \
			  ft_strlcpy.c \
			  ft_strlcat.c \
			  ft_strrchr.c \
			  ft_strnstr.c \
			  ft_strncmp.c \
			  ft_atoi.c \
			  ft_itoa.c \
			  ft_substr.c \
			  ft_strjoin.c \
			  ft_strmapi.c \
			  ft_putchar_fd.c \
			  ft_putstr_fd.c \
			  ft_putendl_fd.c \
			  ft_strdup.c \
			  ft_split.c\
			  ft_isdigit.c\
			 
				
OBJS		= $(SRCS:%.c=%.o)


FLAGS		= -Wall -Werror -Wextra

$(NAME):
	gcc $(FLAGS) -c $(SRCS) -I ./
	ar rc $(NAME) $(OBJS)

all: $(NAME)

bonus: $(NAME)
	gcc $(FLAGS) -c -I ./
	ar rc $(NAME) 

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean flean re bonus
