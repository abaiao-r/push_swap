/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_movements.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 12:41:22 by andrefranci       #+#    #+#             */
/*   Updated: 2023/02/01 18:25:21 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* reverse_rotation_* (rr*): The last element of a stack becomes 
the first element of the same stack.  */
void	reverse_rotation(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*last;
	t_stack	*before_last;

	if (stack == NULL || (*stack)->next == NULL)
		return ;
	last = ft_lstlast(*stack);
	before_last = ft_lst_before_last(*stack);
	temp = *stack;
	*stack = last;
	(*stack)->next = temp;
	before_last->next = NULL;
}

void	reverse_rotation_a(t_stack **stack_a)
{
	reverse_rotation(stack_a);
	write(1, "rra\n", 4);
}

void	reverse_rotation_b(t_stack **stack_b)
{
	reverse_rotation(stack_b);
	write(1, "rrb\n", 4);
}

void	reverse_rotation_r(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotation(stack_a);
	reverse_rotation(stack_b);
	write(1, "rrr\n", 4);
}
