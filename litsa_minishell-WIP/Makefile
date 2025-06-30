NAME = minishell
SRC = main.c echo.c env.c cd.c pwd.c export.c show_var.c unset.c \
		redirect.c exit.c execute_command.c cat.c redirect.c \
		
OBJ = $(SRC:.c=.o)
CC = gcc
FLAGS = -Wall -Wextra -Werror
LIBS = -lreadline -L./libft -lft
INC = -I./libft
RM = rm -f

$(NAME): $(OBJ)
	$(MAKE) -C libft
	$(CC) $(FLAGS) -o $(NAME) $(OBJ)

all: $(NAME)

clean:
	$(MAKE) -C libft clean
	$(RM) $(OBJ)