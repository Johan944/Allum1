##
## Makefile for  in /home/ganem-_j/SDL
##
## Made by johan ganem--brunet
## Login   <ganem-_j@epitech.net>
##
## Started on  Sun Feb 14 16:03:55 2016 johan ganem--brunet
## Last update Sun Feb 21 14:47:39 2016 johan ganem--brunet
##

NAME            = allum1


LDFLAGS         +=	-L/home/$(USER)/.froot/lib/ -llapin
LDFLAGS         +=	-lsfml-audio -lsfml-graphics
LDFLAGS		+=	-lsfml-window -lsfml-system -lstdc++ -ldl
LDFLAGS		+=	-lSDL -lSDL_mixer

CFLAGS		=	-O3

SRCS            =	srcs/main.c \
			srcs/count_matches.c \
			srcs/ia.c \
			srcs/one_player.c \
			srcs/two_players.c \
			srcs/disp_lines.c \
			srcs/init.c \
			srcs/disp_numbers.c \
			srcs/return_numbers.c \
			srcs/win.c \
			srcs/sound.c \
			srcs/functions.c \
			srcs/error.c \
			srcs/search_limits.c \

OBJS            =	$(SRCS:.c=.o)

CC              =	gcc

RM              =	rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(LDFLAGS) $(CFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
