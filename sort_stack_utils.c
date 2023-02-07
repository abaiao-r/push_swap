/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:23:32 by andrefranci       #+#    #+#             */
/*   Updated: 2023/02/07 13:59:44 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
