# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thomas <thomas@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/05 14:00:33 by marvin            #+#    #+#              #
#    Updated: 2021/05/21 07:46:24 by thomas           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FILES := \
		srcs/ft_atoi.c \
		srcs/ft_bzero.c \
		srcs/ft_calloc.c \
		srcs/ft_isalnum.c \
		srcs/ft_isalpha.c \
		srcs/ft_isascii.c \
		srcs/ft_isdigit.c \
		srcs/ft_isprint.c \
		srcs/ft_memccpy.c \
		srcs/ft_memchr.c \
		srcs/ft_memcmp.c \
		srcs/ft_memcpy.c \
		srcs/ft_memmove.c \
		srcs/ft_memset.c \
		srcs/ft_putchar_fd.c \
		srcs/ft_putendl_fd.c \
		srcs/ft_putstr_fd.c \
		srcs/ft_split.c \
		srcs/ft_strchr.c \
		srcs/ft_strdup.c \
		srcs/ft_strjoin.c \
		srcs/ft_strlcpy.c \
		srcs/ft_strlen.c \
		srcs/ft_strmapi.c \
		srcs/ft_strncmp.c \
		srcs/ft_strnstr.c \
		srcs/ft_strrchr.c \
		srcs/ft_substr.c \
		srcs/ft_tolower.c \
		srcs/ft_toupper.c \
		srcs/ft_itoa.c \
		srcs/ft_putnbr_fd.c \
		srcs/ft_strlcat.c \
		srcs/ft_strtrim.c \
		srcs/ft_strcpy.c \
		srcs/ft_iswhitespace.c \
		srcs/ft_reverse.c \
		srcs/ft_swap.c \
		srcs/ft_atoi_base.c \
		srcs/ft_lstsize_bonus.c

OBJS	= ${FILES:.c=.o}
OBJSBONUS = ${BONUSFILES:.c=.o}
BONUSFILES = srcs/ft_lstnew_bonus.c srcs/ft_lstadd_front_bonus.c srcs/ft_lstsize_bonus.c srcs/ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c
HEADER = includes

CC = gcc

NAME	= libft.a

RM 		= rm -rf

CFLAGS	= -Wall -Wextra -Werror -I $(HEADER)

all: $(NAME)

$(NAME): $(OBJS) $(HEADER)
		ar rcs $(NAME) $(OBJS)
		ranlib $(NAME)

bonus: $(OBJS) $(HEADER) $(OBJSBONUS) 
		$(CC) $(CFLAGS) -c $(FILES) $(BONUSFILES)
		ar rcs $(NAME) $(OBJS) $(OBJSBONUS)
		ranlib $(NAME)

clean:
	$(RM) $(OBJS) $(OBJSBONUS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
