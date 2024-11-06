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

SRC_PATH := source/

LIB_PATH := libft/

SOURCE := $(SRC_PATH)/args.c \
		$(SRC_PATH)/get_list_utils.c \
		$(SRC_PATH)/push_swap.c \
		$(SRC_PATH)/sort.c \
		$(SRC_PATH)/arg_utils.c \
		$(SRC_PATH)/sort_reverse.c \
		$(SRC_PATH)/count_steps.c \
		$(SRC_PATH)/list_utils.c \
		$(SRC_PATH)/rotate.c \
		$(SRC_PATH)/sort_utils.c \
		$(SRC_PATH)/free_err.c \
		$(SRC_PATH)/push.c \
		$(SRC_PATH)/r_rotate.c \
		$(SRC_PATH)/swap.c 
		
LIBFT := $(LIB_PATH)/ft_atoi.c \
	 	$(LIB_PATH)/ft_putendl_fd.c \
		$(LIB_PATH)/ft_strjoin.c \
		$(LIB_PATH)/ft_strmapi.c \
		$(LIB_PATH)/ft_substr.c \
		$(LIB_PATH)/ft_isdigit.c \
	 	$(LIB_PATH)/ft_putstr_fd.c \
		$(LIB_PATH)/ft_strlcat.c \
		$(LIB_PATH)/ft_strncmp.c \
		$(LIB_PATH)/ft_itoa.c \
		$(LIB_PATH)/ft_split.c \
		$(LIB_PATH)/ft_strlcpy.c \
	 	$(LIB_PATH)/ft_strnstr.c \
		$(LIB_PATH)/ft_putchar_fd.c \
	 	$(LIB_PATH)/ft_strdup.c \
	 	$(LIB_PATH)/ft_strlen.c \
	 	$(LIB_PATH)/ft_strrchr.c \
	 	$(LIB_PATH)/ft_calloc.c \
	 	$(LIB_PATH)/ft_memset.c \

SRC_OBJS = $(SOURCE:.c=.o) 
LIBFT_OBJS = $(LIBFT:.c=.o)

all : $(NAME)
	 	
$(NAME): $(SRC_OBJS) $(LIBFT_OBJS)
	$(CC) $(CFLAGS) $(SRC_OBJS) $(LIBFT_OBJS) -o $(NAME) -I ./

clean : 
		rm -f $(SRC_OBJS) $(LIBFT_OBJS)

fclean : clean
		rm -f $(NAME) $(SRC_OBJS) $(LIBFT_OBJS)

re: fclean all

.PHONY: all clean fclean re
