NAME = philo
SRCS = main.c init.c routine.c death_monitor.c utils.c threads.c destroy_mutexes.c
OBJS = $(SRCS:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror -pthread
CFLAGS += -fsanitize=thread -g
#LDFLAGS += -fsanitize=thread
all: $(NAME)
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re