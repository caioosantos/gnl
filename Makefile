NAME = get_next_line

CC = gcc
FLAGS = -Wall -Wextra -Werror -g3

SRCS = 	get_next_line.c \
		get_next_line_utils.c \
		main.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS)

re: fclean all

run: $(NAME)
	./$(NAME)

gdb: $(NAME)
	gdb -tui ./$(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

rm: fclean all

.PHONY: all gdb clean fclean re
