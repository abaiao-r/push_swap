/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:30:03 by andrefranci       #+#    #+#             */
/*   Updated: 2023/02/10 16:28:59 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack_n(t_stack **stack_a, t_stack **stack_b)
{
	/* int	i; */
	int	j;

	/* i = count_digits_binary(ft_lstsize(*stack_a)) - 1; */
	j = 0;
	while (!check_sorted(stack_a))
	{
		if ((*stack_a)->rank_binary[j] == '1')
		{
			rotate_a(stack_a);
		}
		else
		{
			push_b(stack_a, stack_b);
		}
		push_a(stack_b, stack_a);
		j++;
	}
}

/* void	sort_stack_n(t_stack **stack_a, t_stack **stack_b)
{
	int	stack_size;

	stack_size = ft_lstsize(*stack_a);
	while (stack_size > 3)
	{
		*stack_a = rotate_to_lowest_number(*stack_a);
		push_b(stack_a, stack_b);
		stack_size--;
	}
	sort_stack_3(stack_a);
	while (*stack_b != NULL)
	{
		push_a(stack_b, stack_a);
	}
}
 */