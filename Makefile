# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: meltremb <meltremb@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/06 10:35:09 by meltremb          #+#    #+#              #
#    Updated: 2022/09/06 12:54:48 by meltremb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C = clang

NAME = push_swap.a

HEADER = push_swap.h

LIBFT = libft \

SRCS = base_moves.c \
	   moves.c \
	   push_swap.c \
	   libftimports.c \
	   utils.c \
	   more_utils.c \
	   looker.c \

CC = gcc
CFLAGS = -Wall -Wextra -Werror -c
AR = ar rc
RM = rm -f
OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	@make -C $(LIBFT)
	@cp libft/libft.a ./$(NAME)
	@ar rc $(NAME) $(OBJS)
	$(CC) $(CFLAGS) $(SRCS)
	$(AR) $(NAME) $(OBJS)

all: $(NAME)

clean:
		$(RM) $(OBJS)
		@make clean -C $(LIBFT)

fclean: clean
		$(RM) $(NAME)
		@make clean -C $(LIBFT)

re: fclean all

.PHONY: all clean fclean re
