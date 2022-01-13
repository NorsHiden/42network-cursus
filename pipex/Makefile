# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/12 21:52:52 by marvin            #+#    #+#              #
#    Updated: 2022/01/12 21:52:52 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS =	dependencies/error_handler.c dependencies/setup.c dependencies/commands.c pipex.c

NAME = pipex

LIBFT = dependencies/libft/libft.a

all : $(NAME)

$(NAME) : $(LIBFT) $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) $(LIBFT) -o $(NAME)

$(LIBFT) :
	make -C dependencies/libft

clean :
	make clean -C dependencies/libft

fclean :
	make fclean -C dependencies/libft
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re