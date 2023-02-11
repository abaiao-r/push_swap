/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefrancisco <andrefrancisco@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 16:34:24 by abaiao-r          #+#    #+#             */
/*   Updated: 2023/02/11 14:15:52 by andrefranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	(void)argc;
	if (argc < 2)
		return (0);
	if (!check_argv(argv))
		return (ft_error());
	stack_b = NULL;
	stack_a = ft_create_stack(argv);
	assign_ranks(&stack_a);
	sort_stack(&stack_a, &stack_b);
	ft_lstclear(&stack_a);
	ft_lstclear(&stack_b);
}
/* int	free_arguments_vector(char **arguments_vector)
{
	int	i;

	i = 0;
	while (arguments_vector[i])
	{
		free(arguments_vector[i]);
		i++;
	}
	free(arguments_vector);
	return (0);
}
int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char 	**argument_vector;

	argument_vector = NULL;
	(void)argc;
	if (argc < 2)
		return (0);
	if (argc == 2)
	{
		argument_vector = ft_split(argv[1], ' ');
		if (!check_argv(argument_vector))
			return (ft_error());
		stack_b = NULL;
		stack_a = ft_create_stack(argument_vector);
		free_arguments_vector(argument_vector);
	}
	else
	{
		if (!check_argv(argv))
			return (ft_error());
		stack_b = NULL;
		stack_a = ft_create_stack(argv);
	}
	assign_ranks(&stack_a);
	sort_stack(&stack_a, &stack_b);
	ft_lstclear(&stack_a);
	ft_lstclear(&stack_b);
} */

/* if you want to print stacks */
/* void	print_stack(t_stack *stack)
{
	while (stack)
	{
		printf("\nNumber:%d Rank:%d Rank_binary:%s \n", stack->number,
				stack->rank, stack->rank_binary);
		stack = stack->next;
	}
} */
