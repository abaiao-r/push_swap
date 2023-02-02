# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/21 16:08:07 by abaiao-r          #+#    #+#              #
#    Updated: 2023/02/02 15:27:22 by abaiao-r         ###   ########.fr        #
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
	$(CC) $(CFLAGS) $(NAME) -o main
	./main
	
clean:	
			$(RM) $(OBJS)

re: fclean $(NAME)

fclean:	clean
				$(RM) $(NAME) main
				
.PHONY: all clean fclean re bonus run