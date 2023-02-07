/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:23:32 by andrefranci       #+#    #+#             */
/*   Updated: 2023/02/07 18:13:27 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*rotate_to_lowest_number(t_stack *stack_a)
{
	int	lowest_number;
	int	distance_top;
	int	stack_size;
	
	lowest_number = find_lowest_number(stack_a);
	distance_top = find_distance_top(stack_a, lowest_number);
	stack_size = ft_lstsize(stack_a);
	if (distance_top <= stack_size / 2)
	{
		while (stack_a->number != lowest_number)
		{
			rotate_a(&stack_a);
		}
	}
	else if (distance_top >= stack_size / 2)
	{
		while (stack_a->number != lowest_number)
		{
			reverse_rotation_a(&stack_a);
		}
	}
	return (stack_a);
}

int	find_distance_top(t_stack *stack, int i)
{
	int	j;

	j = 0;
	if (!stack)
	{
		return (0);
	}
	while (stack->number != i)
	{
		stack = stack->next;
		j++;
	}
	return (j);
}

int	find_lowest_number(t_stack *stack)
{
	int	i;

	i = stack->number;
	while (stack)
	{
		if (stack->number < i)
			i = stack->number;
		stack = stack->next;
	}
	return (i);
}

int	check_sorted(t_stack **stack_a)
{
	t_stack	*temp;

	temp = (*stack_a);
	while (temp)
	{
		if (temp->number > temp->next->number)
			return (0);
		temp = temp->next;
	}
	return (1);
}
