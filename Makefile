# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aokhapki <aokhapki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/14 12:40:49 by aokhapki          #+#    #+#              #
#    Updated: 2024/05/14 16:59:58 by aokhapki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCE			= push_swap.c

LIBFT			= $(LIBFT_DIR)/libft.a

FT_PRINTF		= $(FT_PRINTF_DIR)/libftprintf.a

CC				= cc

CFLAGS			= -Wall -Wextra -Werror -I.

LIBFT_DIR		= libft

FT_PRINTF_DIR	= ft_printf

RM				= rm -f

NAME			= push_swap

push_swap:		$(SOURCE) $(LIBFT) $(FT_PRINTF)
				$(CC) $(CFLAGS) -o $@ $(SOURCE) -L$(LIBFT_DIR) -lft -L$(FT_PRINTF_DIR) -lftprintf

all:			$(NAME)

clean:			$(MAKE) -C $(LIBFT_DIR) clean
				$(MAKE) -C $(FT_PRINTF_DIR) clean
				$(RM) $(NAME)

fclean:			clean
				$(MAKE) -C $(LIBFT_DIR) fclean
				$(MAKE) -C $(FT_PRINTF_DIR) fclean

re:				fclean all

.PHONY:			all clean fclean re 