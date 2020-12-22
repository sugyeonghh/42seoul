# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shong <shong@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/21 16:32:47 by shong             #+#    #+#              #
#    Updated: 2020/12/22 18:36:31 by shong            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a
SRCS	=
			ft_strlen.c
			ft_strlcpy.c
			ft_strlcat.c
			ft_stchr.c
			ft_strchr.c
			ft_strnstr.c
			ft_strncmp.c
			ft_atoi.c
			ft_isalpha.c
			ft_isalpha.c
			ft_isdigit.c
			ft_isalnum.c
			ft_isascii.c
			ft_isprint.c
			ft_touppser.c
			ft_tolower.c
			ft_calloc.c
			ft_strdup.c

			ft_putchar_fd.c
			ft_putstr_fd.c
			ft_putendl_fd.c
			ft_putnbr_fd.c


OBJS	=	$(SRCS:.c=.o)
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror

.c.o:
			$(CC) $(CFLAGS) -I includes -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
			ar rcs $(NAME) $(OBJS)

all:		$(NAME)

clean:
			rm -f $(OBJS)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY: all clean fclean re