# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thkumara <thkumara@student.42singapor      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/02 16:59:39 by thkumara          #+#    #+#              #
#    Updated: 2024/11/02 17:06:17 by thkumara         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk
SERVER = server
CLIENT = client
CC = cc
CFLAGS = -Wall -Wextra -Werror
INC_DIR = inc
SRC_DIR = source

SERVER_SRCS = $(SRC_DIR)/server.c \
           		$(SRC_DIR)/ft_libft.c \
               	$(SRC_DIR)/ft_printf.c \
        		$(SRC_DIR)/printf_util.c \
            	$(SRC_DIR)/printf_utils.c 


CLIENT_SRCS = $(SRC_DIR)/client.c \
               $(SRC_DIR)/ft_libft.c \
        		$(SRC_DIR)/ft_printf.c \
        		$(SRC_DIR)/printf_util.c \
            	$(SRC_DIR)/printf_utils.c 

SERVER_OBJS = $(SERVER_SRCS:.c=.o)
CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)

all: $(SERVER) $(CLIENT)

%.o: %.c
	$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@

$(SERVER): $(SERVER_OBJS)
	$(CC) $(CFLAGS) -I $(INC_DIR) $(SERVER_OBJS) -o $(SERVER)

$(CLIENT): $(CLIENT_OBJS)
	$(CC) $(CFLAGS) -I $(INC_DIR) $(CLIENT_OBJS) -o $(CLIENT)

clean:
	rm -f $(SERVER_OBJS) $(CLIENT_OBJS)

fclean: clean
	$(RM) $(SERVER) $(CLIENT)

re: fclean all

.PHONY: all clean fclean re
