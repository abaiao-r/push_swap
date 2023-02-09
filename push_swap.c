/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefrancisco <andrefrancisco@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 16:34:24 by abaiao-r          #+#    #+#             */
/*   Updated: 2023/02/09 14:26:17 by andrefranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (0);
	if (!check_argv(argv))
		return (ft_error());
	stack_b = NULL;
	stack_a = ft_create_stack(argv);
	sort_stack(stack_a, stack_b);
} */

/* main para testar a criacao do stack a; */
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
	/* stack_a1 = stack_a; */
	print_stack(stack_a);
	sort_stack(&stack_a, &stack_b);
	print_stack(stack_a);
	/* push_b(&stack_a1, &stack_b);
	push_b(&stack_a1, &stack_b);
	swap_b(&stack_b);
	rotate_a(&stack_a1); */
}

void	print_stack(t_stack *stack)
{
	while (stack)
	{
		printf("\nNumber:%d Rank:%d\n", stack->number, stack->rank);
		stack = stack->next;
	}
}
