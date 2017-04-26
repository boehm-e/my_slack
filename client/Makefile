NAME	=	my_slack_client

SRC	=	main.c \

OBJ	=	$(SRC:%.c=%.o)

RM	=	rm -Rf

GCFLAGS =	gcc -g -W -Wall -Werror -ansi -pedantic

LDFLAGS	=	-L./libmy -lmy -static

all	:	$(NAME)

$(NAME)	:	lib	\
		$(OBJ)
		$(CC) -o $(NAME) $(CFLAGS) $(OBJ) $(LDFLAGS)

clean	:
		$(RM) $(OBJ)
		$(RM) *~
		$(RM) #*#
		$(RM) $(NAME)

fclean	:	clean
		$(RM) $(NAME)

%.o	:	%.c
		$(GCFLAGS) -c $< -o $@

re	:	fclean all

lib	:
		cd libmy;make re;make clean;cd -;

run	:
		./my_slack

.PHONY	:	all clean fclean re
