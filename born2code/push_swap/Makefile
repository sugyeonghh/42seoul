# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shong <shong@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/12 19:18:17 by shong             #+#    #+#              #
#    Updated: 2021/07/05 05:24:29 by shong            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

LIBFT = libft.a
LIBS = -L./libft/ -lft 


FILES = push_swap \
		exception \
		stack \
		pivot \
		sorting/sort \
		sorting/sort_under_five \
		sorting/quick_sort \
		actions/swap \
		actions/push \
		actions/rotate \
		actions/reverse_rotate \

SRCS_DIR = ./srcs/
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))

OBJS_DIR = ./srcs/
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))

.c.o: $(SRCS)
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) $(LIBS) -I./includes/

$(NAME): $(OBJS) $(LIBFT)
	$(CC) -o $(NAME) $(OBJS) $(LIBS) -I./includes/

all: $(NAME) $(LIBFT)

$(LIBFT): libft/*.c
	make -C libft

clean:
	make clean -C libft
	$(RM) $(OBJS)

fclean: clean
	make fclean -C libft
	$(RM) $(NAME)

re: clean all

.PHONY: all clean fclean re
