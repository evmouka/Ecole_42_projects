# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: evmouka <evmouka@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/28 16:27:07 by evmouka           #+#    #+#              #
#    Updated: 2024/02/20 20:52:02 by evmouka          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:=		libftprintf.a
SRCS	:=		ft_printf.c ft_parse.c ft_print_char.c ft_print_int.c ft_print_str.c \
				ft_print_ptr.c
				
OBJS	=		$(SRCS:.c=.o)
CC		:=		cc
CFLAGS	:=		-Wall -Werror -Wextra
HEADERS :=		ft_printf.h
AR		:=		ar rcs
RM		:=		rm -f

%.o:		%.c
			$(CC) $(CFLAGS) $ -c $< -o $@

$(NAME):	$(OBJS)
			$(AR) $@ $^

all:		$(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
