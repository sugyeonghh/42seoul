# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sook-yeon <sook-yeon@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/14 23:13:39 by sook-yeon         #+#    #+#              #
#    Updated: 2020/12/20 02:57:32 by sook-yeon        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRCS = display.c find_square.c pre_processing.c main.c
OBJS = $(SRCS:.c=.o)
INC = -I./includes
CC = gcc
CFLAGS = -Wall -Wextra -Werror

.c.o:
		$(CC) $(CFLAGS) $(INC) -c $< -o $(<:.c=.o)

$(NAME): $(OBJS)
		ar rcs $(NAME) $(OBJS)
		$(CC) -o a.out *.o
		./a.out map1

all:	$(NAME)

clean:
		rm -f *.o

fclean:	clean
		rm -f $(NAME) a.out

re:		fclean all

.PHONY: all clean fclean re