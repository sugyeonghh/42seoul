# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shong <shong@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/12 19:18:17 by shong             #+#    #+#              #
#    Updated: 2021/10/05 23:21:51 by shong            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CHECKER = checker

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

LIBFT = libft.a
LIBS = -L./libft/ -lft 

FILES = push_swap \
		preprocessing \
		stack \
		pivot \
		free_stack \
		sorting/sort \
		sorting/sort_under_four \
		sorting/sort_over_four \
		actions/swap \
		actions/push \
		actions/rotate \
		actions/reverse_rotate \

FILES_C = push_swap_checker \
		  checker \
		  get_next_line/get_next_line \
		  get_next_line/get_next_line_utils \
		  ../preprocessing \
		  ../stack \
		  ../pivot \
		  ../free_stack \
		  ../sorting/sort \
		  ../sorting/sort_under_four \
		  ../sorting/sort_over_four \
		  actions/swap \
		  actions/push \
		  actions/rotate \
		  actions/reverse_rotate \


SRCS_DIR = ./srcs/
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))

OBJS_DIR = ./srcs/
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))

SRCS_C_DIR = ./srcs/checker/
SRCS_C = $(addprefix $(SRCS_C_DIR), $(addsuffix .c, $(FILES_C)))

OBJS_C_DIR = ./srcs/checker/
OBJS_C = $(addprefix $(OBJS_C_DIR), $(addsuffix .o, $(FILES_C)))

.c.o: $(SRCS) $(SRCS_C)
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJS) $(OBJS_C) $(LIBFT)
	$(CC) -o $(NAME) $(OBJS) $(LIBS) -I./includes/
	$(CC) -o $(CHECKER) $(OBJS_C) $(LIBS) -I./includes/

all: $(NAME) $(CHECKER) $(LIBFT)

$(LIBFT): libft/*.c
	make -C libft

clean:
	make clean -C libft
	$(RM) $(OBJS) $(OBJS_C)

fclean: clean
	make fclean -C libft
	$(RM) $(NAME) $(CHECKER)

re: clean all

.PHONY: all clean fclean re
