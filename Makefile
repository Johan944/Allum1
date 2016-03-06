##
## Makefile for  in /home/ganem-_j/rendu/PSU_2015_minishell1
##
## Made by johan ganem--brunet
## Login   <ganem-_j@epitech.net>
##
## Started on  Sat Jan 23 23:04:18 2016 johan ganem--brunet
## Last update Sun Feb 21 16:09:49 2016 johan ganem--brunet
##

SRCS           =		srcs/main.c \
				srcs/check.c \
				srcs/disp.c \
				srcs/get_next_line.c \
				srcs/ia.c \
				srcs/input.c \
				srcs/functions.c \

NAME		=		allum1

OBJ		=		$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(SRCS)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
