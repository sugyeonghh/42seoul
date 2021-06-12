# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shong <shong@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/12 19:18:17 by shong             #+#    #+#              #
#    Updated: 2021/06/12 23:56:32 by shong            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

FILES = pipex \
		redirect \
		utils \

SRCS_DIR = ./
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))

OBJS_DIR = ./
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))


$(NAME): $(OBJS)
	make -C libft
	$(CC) -o $(NAME) $(OBJS) -L libft/ -lft

.c.o: $(SRCS)
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -L libft/ -lft

all: $(NAME)

clean:
	$(RM) $(OBJS) $(OBJS_B)

fclean: clean
	$(RM) $(NAME)

re: clean all

.PHONY: all clean fclean re
