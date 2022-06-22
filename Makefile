# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbarreto <mbarreto@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/06 19:35:58 by mbarreto          #+#    #+#              #
#    Updated: 2022/06/22 14:00:07 by mbarreto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS = main.c prep.c inits.c updates.c walking.c exit.c get_next_line.c \
		get_next_line_utils.c ft_conv.c ft_printf.c ft_puts.c side.c \
		ft_split.c ft_strdup.c strjoin.c strlen.c ft_substr.c ft_putstr.c

OBJS = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Wall -Werror -Wextra

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c
	$(CC) -Imlx -Imac -O3 -c $< -o $@
##-g -fsanitize=address 

all: $(NAME)

clean:
	rm -rf $(OBJS)

fclean:	clean
	rm -rf $(NAME)

re: fclean all