# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aokhapki <aokhapki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/14 12:40:49 by aokhapki          #+#    #+#              #
#    Updated: 2024/11/21 16:41:17 by aokhapki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME			= push_swap

# Compiler and CFlags
CC				= cc
CFLAGS			= -Wall -Werror -Wextra
RM				= rm -f

# Source Files
SRCS 			= 	push_swap.c \
					checkers.c \
					catch_error.c \
					ft_atoi.c \
					ft_split.c \
					operators.c \
					parsing.c \
					rank_numbers.c \
					sorting.c \
					utils.c
					
# Objects		
OBJS 			= 	$(SRCS:.c=.o)

# Commands
all:			$(NAME)
$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)
clean:
				$(RM) $(OBJS)
fclean:			clean
				$(RM) $(NAME)
re:				fclean $(NAME)
bonus:			$(OBJS) 
				ar rcs $(NAME) $(OBJS)
.PHONY:			all clean fclean re 