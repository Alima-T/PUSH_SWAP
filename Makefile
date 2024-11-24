# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aokhapki <aokhapki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/14 12:40:49 by aokhapki          #+#    #+#              #
#    Updated: 2024/11/24 20:04:59 by aokhapki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= push_swap

CC				= gcc
CFLAGS			= -Wall -Werror -Wextra
RM				= rm -f

SRCS 			=	checkers.c \
					fill_stack.c \
					ft_atoi.c \
					ft_split.c \
					ft_putendl_fd.c \
					gets.c \
					sets.c \
					push.c \
					push_swap.c \
					rotate.c \
					reverse_rotate.c \
					swap.c \
					sorting.c

OBJS 			=	$(SRCS:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Commands
all:				$(NAME)

$(NAME):			$(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean:				clean
	$(RM) $(NAME)

re:					fclean all

.PHONY:				all clean fclean re