# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: andrefrancisco <andrefrancisco@student.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/21 16:08:07 by abaiao-r          #+#    #+#              #
#    Updated: 2023/02/12 19:10:19 by andrefranci      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = 	check_argv_utils.c \
		check_argv_utils2.c \
		check_argv.c \
		ft_create_stack.c \
		ft_create_stack_utils.c \
 		ft_create_stack_utils2.c \
		ft_split.c \
		push_movements.c \
		push_swap.c \
		reverse_rotate_movements.c \
		rotate_movements.c \
		swap_movements.c \
		sort_stack.c \
		sort_stack2.c \
		sort_stack_utils.c \
		sort_stack_utils2.c


OBJS = $(SRC:.c=.o)


CFLAGS = -Wall -Wextra -Werror -g

CC= cc 

RM = rm -rf 


all: $(NAME)
	
$(NAME): $(OBJS)
		$(CC) $(CFLAGS) $(SRC) -o $(NAME) -fsanitize=address

clean:	
			$(RM) $(OBJS)

fclean:	clean
				$(RM) $(NAME)
re: fclean all
				
.PHONY: all clean fclean re bonus run