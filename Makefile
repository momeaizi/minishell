
   
NAME = minishell

CC = cc

CFLAGS = -Wall -Wextra -Werror

.PHONY = all clean fclean re

SRCS = *.c expanding/*.c libft/*.c libft/list/*.c libft/string/*.c libft/string/split/*.c

OBJS :=$(SRCS:.c=.o)

all : $(NAME)

#$(NAME) : $(OBJS)
#	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)


$(NAME) :
	$(CC) -lreadline $(SRCS) -o $(NAME)
clean :
	rm -f $(OBJS)
fclean : clean
	rm -f $(NAME)
re : fclean all