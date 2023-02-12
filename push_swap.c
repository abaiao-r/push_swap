/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefrancisco <andrefrancisco@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 16:34:24 by abaiao-r          #+#    #+#             */
/*   Updated: 2023/02/12 19:36:08 by andrefranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* The main function first checks if there are less than two 
arguments, in which case it returns 0. 

If there are two arguments, it splits the second argument into 
an array of strings and checks the validity of the numbers. 

If all the numbers are valid, it creates a linked list 
representation of the stack from the arguments. 

If there are more than two arguments, it simply checks the validity 
of the arguments and creates the stack representation.

The function push_swap takes in stack_a and stack_b as arguments, 
assigns ranks to the elements in stack_a using the assign_ranks function, 
sorts the elements in stack_a with sort_stack, and finally frees 
the linked lists with ft_lstclear. */

static void	push_swap(t_stack *stack_a, t_stack *stack_b)
{
	assign_ranks(&stack_a);
	sort_stack(&stack_a, &stack_b);
	ft_lstclear(&stack_a);
	ft_lstclear(&stack_b);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**argument_vector;

	argument_vector = NULL;
	if (argc < 2)
		return (0);
	if (argc == 2)
	{
		argument_vector = ft_split(argv[1], ' ');
		if (!check_argv(argc, argument_vector))
			return (ft_error());
		stack_b = NULL;
		stack_a = ft_create_stack(argument_vector);
		free_arguments_vector(argument_vector);
	}
	else
	{
		if (!check_argv(argc, argv))
			return (ft_error());
		stack_b = NULL;
		stack_a = ft_create_stack(argv);
	}
	push_swap(stack_a, stack_b);
}

/* Ifyou want to print stacks you also need to add the prototype 
to push_swap.h */
/* void	print_stack(t_stack *stack)
{
	while (stack)
	{
		printf("\nNumber:%d Rank:%d Rank_binary:%s \n", stack->number,
				stack->rank, stack->rank_binary);
		stack = stack->next;
	}
} */
