NAME	=	exec

CC	=	gcc

RM	=	rm -f

CFLAGS	=	-W -Wall -Wextra -Werror -ansi

SRCS	=	main.c

OBJS	=	$(SRCS:.c=.o)

INC	=	-I.

all:		$(NAME)

.PHONY:		all re clean fclean

re:		fclean all

$(NAME):	$(OBJS)
		$(CC) $(INC) -o $(NAME) $(OBJS)

clean:
		@$(RM) $(OBJS)

fclean:		clean
		@$(RM) $(NAME)

.c.o:
		$(CC) $(INC) $(CFLAGS) -o $@ -c $<
