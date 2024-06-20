# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: evmouka <evmouka@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/22 13:25:55 by evmouka           #+#    #+#              #
#    Updated: 2024/06/14 18:20:26 by evmouka          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAMES := server
NAMEC := client
SRCS := server.c
SRCC := client.c
OBJS = $(SRCS:.c=.o)
OBJC = $(SRCC:.c=.o)
PRINTF = libftprintf.a
LIBFT = libft.a
INCLUDES := -I./libft -I./ft_printf
HEADER := minitalk.h
AR := rcs
CC := cc	
CFLAGS := -Wall -Werror -Wextra -g $(INCLUDES)
RM := rm -f

all: $(NAMES) $(NAMEC)

$(LIBFT):
	make -C libft

$(PRINTF):
	make -C ft_printf 

$(NAMES): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS) ./libft/libft.a ./ft_printf/libftprintf.a

$(NAMEC): $(OBJC) 
	$(CC) $(CFLAGS) -o $@ $(OBJC) ./libft/libft.a ./ft_printf/libftprintf.a
	
$(OBJS): %.o: %.c 
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES) 

$(OBJC): %.o: %.c 
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)



clean:
	$(RM) $(OBJS) $(OBJC) ./libft/*.o ./ft_prinft/*.o

fclean: clean
	$(RM) $(NAMES) $(NAMEC) $(OBJS) $(OBJC)

re: fclean all

.PHONY: all clean fclean re
