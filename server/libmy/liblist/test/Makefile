##
## Makefile for  in /home/boehm_s/DEV_C/Libmy/boehm_s/libmy_01
##
## Made by BOEHM Steven
## Login   <boehm_s@etna-alternance.net>
##
## Started on  Sat Oct  4 18:59:41 2014 BOEHM Steven
## Last update Fri Feb  3 11:03:55 2017 BOEHM Steven
##

CC	=	gcc
NAME	=	liblist_test

SRC	=	../list.c		\
		main.c

OBJ	=	$(SRC:%.c=%.o)

RM	=	rm -Rf

GCFLAGS =	gcc -g03 -W -Wall -Werror -ansi -pedantic

$(NAME)	:	$(OBJ)
		$(CC) $(SRC) -o $(NAME) $(CFLAGS) $(SDLFLAGS) $(LDFLAGS)

all	:	$(NAME)

clean	:
		$(RM) $(OBJ)
		$(RM) *~
		$(RM) #*#

fclean	:	clean
		$(RM) $(NAME)

%.o	:	%.c
		$(GCFLAGS) -c $< -o $@

re	:	fclean all

run	:
		./liblist_test

.PHONY	:	all clean fclean re run
