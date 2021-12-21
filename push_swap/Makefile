# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nelidris <nelidris@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/21 14:19:05 by nelidris          #+#    #+#              #
#    Updated: 2021/12/21 15:58:46 by nelidris         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror

AR = ar rs

NAME = push_swap.a

CHECKER = checker.a

PATH = dependencies

LINKED_L = linked_l

B_PATH = b_dependencies

SRCS =	$(PATH)/build_utils.c $(PATH)/ft_atoi.c $(PATH)/ft_memcpy.c \
		$(PATH)/ft_strlen.c $(PATH)/ft_substr.c \
		$(PATH)/operations.c $(PATH)/raise_error.c $(PATH)/sort_stack.c \
		$(PATH)/sort_utils.c $(PATH)/$(LINKED_L)/ft_lstadd_back_bonus.c \
		$(PATH)/$(LINKED_L)/ft_lstadd_front_bonus.c $(PATH)/$(LINKED_L)/ft_lstclear_bonus.c \
		$(PATH)/$(LINKED_L)/ft_lstlast_bonus.c $(PATH)/$(LINKED_L)/ft_lstnew_bonus.c \
		$(PATH)/$(LINKED_L)/ft_lstsize_bonus.c

CHECKER_SRCS =	$(SRCS) $(B_PATH)/ft_strcmp.c $(B_PATH)/checker_utils.c $(B_PATH)/get_next_line.c $(B_PATH)/get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

CHECKER_OBJS = $(CHECKER_SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(AR) $(NAME) $(OBJS)
	$(CC) $(CFLAGS) push_swap.c $(SRCS) -o push_swap

bonus : $(CHECKER)

$(CHECKER) : $(CHECKER_OBJS)
	$(AR) $(CHECKER) $(CHECKER_OBJS)
	$(CC) $(CFLAGS) ps_checker.c $(CHECKER_SRCS) -o checker

clean:
	rm -f $(CHECKER_OBJS)

fclean:	clean
	rm -f $(NAME) $(CHECKER)

re: fclean all

.PHONY: all bonus clean fclean re