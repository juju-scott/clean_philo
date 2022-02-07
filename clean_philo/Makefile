CFLAGS = -Wall -Wextra -Werror -pthread -g -fsanitize=address
GCC = gcc
NAME = philo

SRC_FILES = main.c\
			parsing.c\
			threads.c\
			routine.c\
			utils_chained_list.c\
			utils.c\
			init.c\
								
SRC = $(SRC_FILES)

OBJ_SRC = $(SRC:.c=.o)

OBJS = $(OBJ_SRC)

all:
		$(MAKE) $(NAME)

$(NAME):	$(OBJS)
			$(GCC) $(CFLAGS) $(OBJS) -o $(NAME)

			
re: fclean all

clean:
		rm -rf $(OBJS)

fclean: clean
		rm -rf $(NAME)


%.o: %.c
		@$(GCC) $(CFLAGS) -c $^ -o $@

.PHONY: all re clean fclean
