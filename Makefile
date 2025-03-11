# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: azorlutu <azorlutu@student.42istanbul.com  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/16 21:51:46 by azorlutu          #+#    #+#              #
#    Updated: 2025/01/16 21:51:47 by azorlutu         ###   ########.tr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = push_swap
CHECKER_NAME = checker

SRC = ft_atol.c handle_errors.c init_nodes.c init_stack.c main.c push_swap.c push.c \
      reverse_rotate.c rotate.c split.c stack_utils.c swap.c tiny_sort.c

CHECKER_SRC = checker.c ft_atol.c handle_errors.c init_nodes.c init_stack.c push_swap.c push.c \
              reverse_rotate.c rotate.c split.c stack_utils.c swap.c tiny_sort.c

OBJ = $(SRC:.c=.o)
CHECKER_OBJ = $(CHECKER_SRC:.c=.o)

RM = rm -f

all: $(NAME)

bonus: $(CHECKER_NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

$(CHECKER_NAME): $(CHECKER_OBJ)
	$(CC) $(CFLAGS) -o $(CHECKER_NAME) $(CHECKER_OBJ)

clean:
	$(RM) $(OBJ) $(CHECKER_OBJ)

fclean: clean
	$(RM) $(NAME) $(CHECKER_NAME)

re: fclean all

.PHONY: all clean fclean re

