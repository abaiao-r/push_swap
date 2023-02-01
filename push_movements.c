/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_movements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 14:36:57 by andrefranci       #+#    #+#             */
/*   Updated: 2023/02/01 18:26:50 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* push_* (p*): The top element of the source stack becomes the top
 element of the stack destination. */
void	push(t_stack **stack_source, t_stack **stack_destination)
{
	t_stack	*temp;

	if (stack_source == NULL)
		return ;
	temp = *stack_source;
	(*stack_source) = (*stack_source)->next;
	ft_lstadd_front(stack_destination, temp);
}

void	push_a(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_b, stack_a);
	write(1, "pa\n", 3);
}

void	push_b(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_a, stack_b);
	write(1, "pb\n", 3);
}
