##
## Makefile for robby in /home/menuge_k/rendu/robby
##
## Made by kevin menuge
## Login   <menuge_k@epitech.net>
##
## Started on  Wed Jun 25 05:34:57 2014 kevin menuge
## Last update Mon Jun 30 23:09:20 2014 kevin menuge
##

SRC	=	src/main.c \
		src/basics.c \
		src/vaccum.c \
		src/grammar.c \
		src/phone.c \
		src/get_next_line.c \
		src/conversation1.c \
		src/conversation.c \
		src/move_robby.c \
		src/move_dab.c \
		src/list_recette.c \
		src/move_diag.c \
		src/parsing_vac.c \
		src/parsing_fridge.c \
		src/parsing_recette.c \
		src/cooking.c

OBJ	=	$(SRC:.c=.o)

NAME	=	Robby

FLAGS	=	-Wall -Werror -Wextra

INCFOLD	=	header/

CFLAGS	=	-I$(INCFOLD)

all:	$(NAME)

$(NAME): $(OBJ)
	cc -o $(NAME) $(OBJ) $(FLAGS)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
