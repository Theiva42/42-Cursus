# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thkumara <thkumara@student.42singapor      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/30 20:01:37 by thkumara          #+#    #+#              #
#    Updated: 2024/05/30 20:02:26 by thkumara         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = libft.a

SRCS        = ft_isalpha.c \
              ft_isdigit.c \
              ft_isalnum.c \
              ft_isascii.c \
              ft_isprint.c \
              ft_toupper.c \
              ft_tolower.c \
              ft_memset.c \
              ft_bzero.c \
              ft_memcpy.c \
              ft_memmove.c \
              ft_memchr.c \
              ft_memcmp.c \
              ft_strlen.c \
              ft_strlcpy.c \
              ft_strlcat.c \
              ft_strchr.c \
              ft_strrchr.c \
              ft_strnstr.c \
              ft_strncmp.c \
              ft_atoi.c \
              ft_itoa.c \
              ft_substr.c \
              ft_strjoin.c \
              ft_strtrim.c \
              ft_split.c \
              ft_strmapi.c \
              ft_striteri.c \
              ft_putchar_fd.c \
              ft_putstr_fd.c \
              ft_putendl_fd.c \
              ft_putnbr_fd.c \
              ft_calloc.c \
              ft_strdup.c

BNS_SRCS    = ft_lstnew.c \
              ft_lstadd_front.c \
              ft_lstsize.c \
              ft_lstlast.c \
              ft_lstadd_back.c \
              ft_lstdelone.c \
              ft_lstclear.c \
              ft_lstiter.c \
              ft_lstmap.c

OBJS        = $(SRCS:.c=.o)
BNS_OBJS    = $(BNS_SRCS:.c=.o)

CFLAGS      = -Wall -Wextra -Werror

# Rule to create object files from source files
%.o: %.c
	gcc $(CFLAGS) -c $< -o $@

# Main target
$(NAME): $(OBJS)
	ar rcs $@ $^

all: $(NAME)

# Bonus target
bonus: $(NAME) $(BNS_OBJS)
	ar rcs $(NAME) $(BNS_OBJS)

# Clean object files
clean:
	rm -f $(OBJS) $(BNS_OBJS)

# Clean object files and the library
fclean: clean
	rm -f $(NAME)

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re bonus
