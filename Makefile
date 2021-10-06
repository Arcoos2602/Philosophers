# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tcordonn <tcordonn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/04 15:15:11 by tcordonn          #+#    #+#              #
#    Updated: 2021/10/05 11:02:12 by tcordonn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
HEAD = -I ./include/ -I ./libft/include

CFLAGS = -Wall -Werror -Wextra

SRCS =  srcs/philo.c
		

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	make -C ./libft
	clang -g $(CFLAGS) $(HEAD) $(OBJS) -o $(NAME) -L./libft -lft

G: $(OBJS)
	make -C ./libft
	clang -g3 -fsanitize=thread $(CFLAGS) $(HEAD) $(OBJS) -o $(NAME) -L./libft -lft

clean:
	rm -rf $(OBJS) objs
	make clean -sC libft

fclean:
	make fclean -sC libft
	rm -rf $(NAME) $(OBJS)

re:	fclean
	make all