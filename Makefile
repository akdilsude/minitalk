NAME_S 	= server
NAME_C 	= client


CFLAGS 	= -Wall -Wextra -Werror
CC 		= cc
RM 		= rm -f

SRCS_S 	= server.c
SRCS_C 	= client.c

OBJS_S 	= $(SRCS_S:.c=.o)
OBJS_C 	= $(SRCS_C:.c=.o)


all: $(NAME_S) $(NAME_C)

$(NAME_S): $(OBJS_S)
	$(CC) $(CFLAGS) $(OBJS_S) -o $(NAME_S)

$(NAME_C): $(OBJS_C)
	$(CC) $(CFLAGS) $(OBJS_C) -o $(NAME_C)


clean:
	$(RM) $(OBJS_S) $(OBJS_C) 

fclean: clean
	$(RM) $(NAME_S) $(NAME_C) 

re: fclean all

.PHONY: all clean fclean re