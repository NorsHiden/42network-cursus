# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nelidris <nelidris@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/23 17:48:01 by nelidris          #+#    #+#              #
#    Updated: 2021/11/24 11:28:44 by nelidris         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC = ft_convert.c ft_printf.c ft_utils.c

OBJ = $(SRC:.c=.o)

NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJ)
	ar rs $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re