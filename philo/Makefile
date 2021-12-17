# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thomas <thomas@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/04 15:15:11 by tcordonn          #+#    #+#              #
#    Updated: 2021/12/16 18:13:16 by thomas           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
HEAD = -I ./include/ -I ./libft/include

CFLAGS = -Wall -Werror -Wextra

SRCS =  srcs/main.c \
		srcs/philo.c \
		srcs/routine.c \
		srcs/init.c \
		srcs/utils.c \
		srcs/libft.c
		

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	clang -g $(CFLAGS) $(HEAD) $(OBJS) -o $(NAME)

G: $(OBJS)
	clang -g3 -fsanitize=thread $(CFLAGS) $(HEAD) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS) objs
	make clean -sC libft

fclean:
	rm -rf $(NAME) $(OBJS)

re:	fclean
	make all