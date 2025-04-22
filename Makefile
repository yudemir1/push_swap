# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yudemir <yudemir@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/08 14:49:52 by yudemir           #+#    #+#              #
#    Updated: 2025/04/08 16:44:05 by yudemir          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = push_swap
NAME_BONUS = checker

CC      = cc
CFLAGS  = -Wall -Wextra -Werror -g
RM      = rm -f

SRCS = algo.c cost.c index.c errors.c op.c op1.c op2.c op3.c parse_utils.c parse.c position.c sort.c stack.c push_swap.c ./gnl/get_next_line.c ./gnl/get_next_line_utils.c
B_SRCS = checker.c algo.c errors.c cost.c index.c op.c op1.c op2.c op3.c parse_utils.c parse.c position.c sort.c stack.c ./gnl/get_next_line.c ./gnl/get_next_line_utils.c
 
B_OBJS = $(B_SRCS:.c=.o)
OBJS    = $(SRCS:.c=.o)

LIBFT_DIR = ./libft
LIBFT     = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	@echo "----compiling $(NAME)----"
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	@echo "----compiling libft----"
	@make -C $(LIBFT_DIR) > /dev/null

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(B_OBJS) $(LIBFT)
	@echo "----compiling $(NAME_BONUS)----"
	@$(CC) $(CFLAGS) $(B_OBJS) $(LIBFT) -o $(NAME_BONUS)

clean:
	@echo "...cleaning object files..."
	@make -C $(LIBFT_DIR) clean > /dev/null
	@$(RM) $(OBJS) $(B_OBJS)

fclean: clean
	@echo "...removing executable..."
	@make -C $(LIBFT_DIR) fclean > /dev/null
	@$(RM) $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: all clean fclean re bonus