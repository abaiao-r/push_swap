# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: andrefrancisco <andrefrancisco@student.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/21 16:08:07 by abaiao-r          #+#    #+#              #
#    Updated: 2023/02/06 14:51:13 by andrefranci      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a

SRC = 	check_argv_utils.c \
		check_argv_utils2.c \
		check_argv.c \
		ft_create_stack.c \
		ft_create_stack_utils.c \
 		ft_create_stack_utils2.c \
		push_movements.c \
		push_swap.c \
		reverse_rotate_movements.c \
		rotate_movements.c \
		swap_movements.c

LIB = push_swap.h

		


OBJS = $(SRC:.c=.o)


CFLAGS = -Wall -Wextra -Werror -g

CC= cc 

RM = rm -rf 

all:	$(NAME)

$(NAME): $(OBJS)
	ar -rcs $@ $^

run: 
	$(CC) $(CFLAGS) $(NAME) -o push_swap
	./push_swap
	
clean:	
			$(RM) $(OBJS)

re: fclean $(NAME)

fclean:	clean
				$(RM) $(NAME) push_swap
				
.PHONY: all clean fclean re bonus run