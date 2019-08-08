##
## Makefile for  in /home/pennam_a/Systeme_unix/PSU_2015_malloc
##
## Made by antoine pennamen
## Login   <pennam_a@epitech.net>
##
## Started on  Fri Feb 12 03:53:07 2016 antoine pennamen
## Last update Sun Feb 14 20:47:08 2016 antoine pennamen
##

SRC_EXE		= malloc.c \
		  free.c \
		  realloc.c \
		  show_alloc_mem.c \
		  calloc.c

OBJ_EXE		= $(SRC_EXE:.c=.o)

NAME_LIB	= libmy_malloc.so

CFLAGS		+= -Werror -Wextra -Wall -W -fPIC

LDFLAGS		= -shared

RM		= rm -f

CC		= gcc

all		: $(NAME_LIB)

$(NAME_LIB)	: $(OBJ_EXE)
		  $(CC) $(LDFLAGS) $(SRC_EXE) -o $(NAME_LIB) $(CFLAGS)

clean		:
		  $(RM) $(OBJ_EXE)

fclean		: clean
		  $(RM) $(NAME_LIB)

re		: fclean all

.PHONY		: re clean fclean all
