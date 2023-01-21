# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/21 16:08:07 by abaiao-r          #+#    #+#              #
#    Updated: 2023/01/21 16:26:33 by abaiao-r         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a

SRC = 

LIB = push_swap.h

		


OBJS = $(SRC:.c=.o)


CFLAGS = -Wall -Wextra -Werror

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