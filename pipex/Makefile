# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/15 17:18:08 by marvin            #+#    #+#              #
#    Updated: 2022/01/15 17:18:08 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror

AR = ar rc

SRCS =	dependencies/errors.c dependencies/pipex.c \
		dependencies/processes.c dependencies/setup.c

OBJS = $(SRCS:.c=.o)

B_SRCS = dependencies/setup.c dependencies/errors.c \
		b_dependencies/b_pipex.c b_dependencies/b_processes.c \
		b_dependencies/get_next_line.c

B_OBJS = $(B_SRCS:.c=.o)

NAME = dependencies/mandatory.a

BONUS = b_dependencies/bonus.a

LIBFT = libft/libft.a

all : $(NAME)

$(NAME) : $(LIBFT) $(OBJS)
	$(AR) $(NAME) $(OBJS)
	$(CC) $(CFLAGS) $(NAME) $(LIBFT) -o pipex

$(LIBFT) :
	make -C libft/

bonus : $(BONUS)

$(BONUS) : $(LIBFT) $(B_OBJS)
	$(AR) $(BONUS) $(B_OBJS)
	$(CC) $(CFLAGS) $(BONUS) $(LIBFT) -o pipex

clean :
	make clean -C libft/

fclean :
	make fclean -C libft/
	rm -f $(OBJS) $(B_OBJS)
	rm -f $(NAME) $(BONUS)

re : fclean all

.PHONY : all bonus clean fclean re