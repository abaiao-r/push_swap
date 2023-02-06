/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefrancisco <andrefrancisco@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 16:33:03 by abaiao-r          #+#    #+#             */
/*   Updated: 2023/02/06 23:16:31 by andrefranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* void	sort_stack_5(t_stack **stack_a, t_stack **stack_b)
{
	int	lowest_number;

	lowest_number = find_lowest_number(*stack_a);
	if ((*stack_a)->number != lowest_number)
	{
		rotate_a(&stack_a);
	}
	else
		push_b(&stack_a, &stack_b);
	sort_stack_4(stack_a, stack_b);
	push_a(&stack_a, &stack_b);
}

void	sort_stack_4(t_stack **stack_a, t_stack **stack_b)
{
	int	lowest_number;

	lowest_number = find_lowest_number(*stack_a);
	if ((*stack_a != lowest_number))
	{
		rotate_a(&stack_a);
	}
	else
		push_b(&stack_a, &stack_b);
	sort_stack_3(stack_a, stack_b);
	push_a(&stack_a, &stack_b);
}

void	sort_stack_3(t_stack **stack_a, t_stack **stack_b)
{
	int	a;
	int	b;
	int	c;

	a = (*stack_a)->number;
	b = (*stack_a)->next->number;
	c = (*stack_a)->next->next->number;
	if (a > b && c < a)
	{
		swap_a(&stack_a);
		rotate_a(&stack_a);
	}
	else if (a > b && c > a)
		swap_a(&stack_a);
	else if (b > a && a > c)
		reverse_rotation_a(&stack_a);
	else if (a > b && b < c)
		rotate_a(&stack_a);
	else if (a > b && b > c)
	{
		swap_a(&stack_a);
		reverse_rotation_a(&stack_a);
	}
} */

void	sort_stack_2(t_stack **stack_a)
{
	if ((*stack_a)->number > (*stack_a)->next->number)
		swap_a(stack_a);
}

void	sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	(void) (*stack_b);
	if (check_sorted(stack_a))
		return ;
	if (ft_lstsize(*stack_a) == 2)
		sort_stack_2(stack_a);
/* 	else if (ft_lstsize(*stack_a) == 3)
		sort_stack_3(stack_a, stack_b);
	else if (ft_lstsize(*stack_a) == 4)
		sort_stack_4(stack_a, stack_b);
	else if (ft_lstsize(*stack_a) == 5)
		sort_stack_5(stack_a, stack_b);
	else
		sort_stack_n(stack_a, stack_b); */
}
