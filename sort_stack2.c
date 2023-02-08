/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:30:03 by andrefranci       #+#    #+#             */
/*   Updated: 2023/02/08 12:49:14 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack_n(t_stack **stack_a, t_stack **stack_b)
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
