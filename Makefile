NAME = minishell

SRCS = minishell.c

CC = cc

CFLAGS = -Wall -Werror -Wextra 

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
		$(CC) $(CFLAGS)  $(OBJS) -o $(NAME) -lreadline
clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all