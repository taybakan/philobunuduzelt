NAME = philo

SRCS = main.c thread_init.c utils.c let_thrb_philos.c routine.c checkinput.c gettime.c write.c ft_calloc.c wait.c azrael.c

OBJS = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Wall -Werror -Wextra -g -pthread

FLAGS_DATARACE = -fsanitize=thread -g

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

data_race:
	@$(CC) $(FLAGS_DATARACE) $(SRCS) -o $(NAME)

clean:
	@rm -rf philo.dSYM
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)
	@rm -rf philo.a

re: fclean all

.PHONY: all clean fclean re
