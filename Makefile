# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wkrati <wkrati@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/10 02:14:41 by wkrati            #+#    #+#              #
#    Updated: 2025/12/20 18:34:23 by wkrati           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = push_swap
BNS_NAME 	= checker

CC          = cc
CFLAGS      = -Wall -Wextra -Werror

AR          = ar
ARFLAGS     = rcs
RM          = rm -f

SRCS = Algo/main.c \
       Algo/push_swap.c \
       Algo/chunk_sort.c \
       Algo/small_sort.c \
	   Operations/swap_ops.c \
       Operations/push_ops.c \
       Operations/rotate_ops.c \
       Operations/rev_rotate_ops.c \
	   utils/stack_utils.c \
	   utils/index_utils.c \
	   utils/parsing_utils.c \
	   utils/sort_utils.c \
	   utils/split_utils.c
	   
OBJS = $(SRCS:.c=.o)

BONUS_SRC = 
BONUS_OBJ = $(BONUS_SRC:.c=.o)


all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(BNS_NAME): $(BONUS_OBJ)
	$(CC) $(CFLAGS) $(BONUS_OBJ) -o $(BNS_NAME)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(BNS_NAME)

clean:
	@$(RM) $(OBJS) $(BONUS_OBJ)

fclean: clean
	@$(RM) $(NAME) $(BNS_NAME)

re: fclean all

.PHONY: all clean fclean re bonus
.SECONDARY: $(OBJS) $(BONUS_OBJ)
