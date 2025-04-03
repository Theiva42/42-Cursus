# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thkumara <thkumara@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/27 14:30:27 by thkumara          #+#    #+#              #
#    Updated: 2025/03/27 14:32:36 by thkumara         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME	= philo

CC	= cc

SRCS	= philo.c\
		monitor_philo.c\
		philo_routine.c\
		utils.c\
		main.c

OBJS	= $(SRCS:%.c=%.o)

FLAGS	= -Wall -Wextra -Werror 

$(NAME): $(OBJS)
		$(CC) $(FLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

all : $(NAME)

clean : 
		rm -f $(OBJS)

fclean : clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
