# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shong <shong@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/24 17:29:35 by shong             #+#    #+#              #
#    Updated: 2021/06/24 17:37:43 by shong            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

FILES = push_swap \
		stack \

SRCS_DIR = ./
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES))

OBJS_DIR = ./
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .c, $(FILES))


all: libft &(NAME)

.c.o: $(SRCS)
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -Llibft -lft

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) -Llibft -lft

libft:
	make -C libft

clean:
	make clean -C libft
	$(RM) $(OBJS)

fclean: clean
	make fclean -C libft
	$(RM) $(NAME)

re: clean all

.PHONY: all clean fclean re

