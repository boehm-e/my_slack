##
##
## Made by BOEHM erwan
## Login   <boehm_e@etna-alternance.net>
##
##

CC =		gcc

CFLAGS +=	-Wall -Wextra -W -g -g03 -pedantic
NAME	=		slack

SRC	=	main.c \
			libmy/my_putchar.c    	\
			libmy/my_isneg.c      	\
			libmy/my_put_nbr.c    	\
			libmy/my_swap.c       	\
			libmy/my_putstr.c     	\
			libmy/my_strlen.c     	\
			libmy/my_getnbr.c     	\
			libmy/my_aff_tab.c    	\
			libmy/my_strcpy.c     	\
			libmy/my_strncpy.c    	\
			libmy/my_strcmp.c     	\
			libmy/my_strncmp.c    	\
			libmy/my_strcat.c     	\
			libmy/my_strncat.c    	\
			libmy/my_strstr.c



OBJ	=	$(SRC:%.c=%.o)  $(SRCS:.c=.o)

RM	=	rm -f

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

all:		$(NAME)

clean:
		$(RM) $(OBJ) $(NAME)

fclean:		clean
		$(RM) $(NAME)

run:		$(NAME)
				./${NAME}

re:		fclean all
