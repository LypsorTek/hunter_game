##
## EPITECH PROJECT, 2023
## makefile
## File description:
## makefile
##


NAME    = my_hunter

CC    = gcc

RM    = rm -f

SRC	=	src/main.c \
		src/sprites.c \
		src/animesprite.c \
		src/scoregestion.c \
		src/help.c \

COMPIL = -l csfml-network -l csfml-system -l csfml-window

OBJS    = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -l csfml-audio -l csfml-graphics $(COMPIL) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
