NAME = get_next_line

CC = gcc
FLAGS = -Wall -Wextra -Werror -g3

SRCS = 	get_next_line.c \
		get_next_line_utils.c \
		main.c

SRCS_BONUS =	get_next_line_bonus.c \
				get_next_line_utils_bonus.c \
				main_bonus.c

OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS)

bonus: $(NAME) $(OBJS_BONUS) $(BONUS_ADDED)

$(BONUS_ADDED): $(OBJS_BONUS)
	ar rcs $(NAME) $(OBJS_BONUS)
	touch $(BONUS_ADDED)


re: fclean all

run: $(NAME)
	./$(NAME)

gdb: $(NAME)
	gdb -tui ./$(NAME)

clean:
	rm -f $(OBJS) $(OBJS_BONUS) $(BONUS_ADDED)

fclean: clean
	rm -f $(NAME)

rm: fclean all

.PHONY: all gdb clean fclean re
