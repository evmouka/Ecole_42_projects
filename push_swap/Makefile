NAME		:=	push_swap
SRCS		=	push_swap.c cost.c sort_small.c utilities0.c utilities1.c utilities2.c utilities3.c utilities4.c main.c
OBJS		:=	$(SRCS:.c=.o)
CC			:=	gcc
FLAGS		:=	-Wall -Werror -Wextra -g #-fsanitize=address
LIBFT		:=	libft.a
LIBFT_DIR	=	libft
LIBFT_LIB	=	$(LIBFT_DIR)/$(LIBFT)
LIBFT_INC	=	-L$(LIBFT_DIR) -lft
RM			=	rm -f

all:		$(NAME) $(LIBFT_DIR)/$(LIBFT)

$(NAME):	$(OBJS)
			@make -C $(LIBFT_DIR)
			@cp $(LIBFT_LIB) .
#			$(NAME)
			$(CC) $(FLAGS) $(SRCS) -o $(NAME) -Wl,-rpath=$(LIBFT_DIR) $(LIBFT_INC)

#%o:	%.c
#		$(CC) -c $(FLAGS)

clean:
		@make clean -C $(LIBFT_DIR)
		$(RM) $(OBJS)

fclean:	clean
		@make clean -C $(LIBFT_DIR)
		$(RM) $(NAME)

re:		fclean all

.PHONY:	all clean fclean re