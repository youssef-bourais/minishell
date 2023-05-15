NAME = minishell

SRCS = minishell.c

CC = cc

CFLAGS = -Wall -Werror -Wextra -lreadline

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all