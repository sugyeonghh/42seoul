# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shong <shong@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/06 02:10:51 by shong             #+#    #+#              #
#    Updated: 2021/02/16 04:00:49 by shong            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

FILES = ft_printf \
		ft_print_type \
		ft_str_filled_with \
		ft_type_c \
		ft_type_p \
		ft_type_s \
		ft_type_di \
		ft_type_ux \

SRCS_DIR = ./
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))

OBJS_DIR = ./
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))


.c.o: $(SRCS)
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJS)
	make -C libft
	cp libft/libft.a $(NAME)
	$(AR) $@ $^

all: $(NAME)

clean:
	make clean -C libft 
	$(RM) $(OBJS) $(NAME)

fclean: clean
	make fclean -C libft
	$(RM) $(NAME)

re: clean all

.PHONY: all clean fclean re
