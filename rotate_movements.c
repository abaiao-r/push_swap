/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_movements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefrancisco <andrefrancisco@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 11:46:41 by andrefranci       #+#    #+#             */
/*   Updated: 2023/02/06 14:51:28 by andrefranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* rotate (r*): the first element of the stack becomes the last element
 of the same stack */
void	rotate(t_stack **stack)
{
	t_stack	*temp;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	temp = *stack;
	*stack = (*stack)->next;
	ft_lstlast(*stack)->next = temp;
	temp->next = NULL;
}

void	rotate_a(t_stack **stack_a)
{
	rotate(stack_a);
	write(1, "ra\n", 3);
}

void	rotate_b(t_stack *stack_b)
{
	rotate(&stack_b);
	write(1, "rb\n", 3);
}

void	rotate_r(t_stack *stack_a, t_stack *stack_b)
{
	rotate(&stack_a);
	rotate(&stack_b);
	write(1, "rr\n", 3);
}