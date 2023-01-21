NAME=push_swap

C_FILES= args_check.c\
		 binary.c\
		 checker_aux.c\
		 ft_atoi.c\
		 ft_calloc.c\
		 ft_isdigit.c\
		 ft_split.c\
		 node_operations.c\
		 push_swap_utils.c\
		 push_swap.c\
		 sort_aux.c\
		 sort_final.c\
		 swap_push_operations.c



O_FILES= $(C_FILES:.c=.o) 

CC=cc
CFLAGS=-Wall -Wextra -Werror -g
REMOVE = rm -rf

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(C_FILES) -o push_swap

clean:
	rm -f $(O_FILES)

fclean: clean
	$(REMOVE) $(NAME)

re: fclean all	

.PHONY: all clean fclean re