# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shong <shong@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/20 02:57:19 by shong             #+#    #+#              #
#    Updated: 2021/06/22 17:45:00 by shong            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

FILES = push_swap \
		swap_stack \
		push_stack \
		rotate_stack \
		find_pivot \

SRCS_DIR = ./
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))

OBJS_DIR = ./
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))

all: libft $(NAME)

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
