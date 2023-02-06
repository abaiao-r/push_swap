/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_movements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefrancisco <andrefrancisco@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 16:12:33 by abaiao-r          #+#    #+#             */
/*   Updated: 2023/02/06 18:08:33 by andrefranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* s (swap_*) */
void	swap(t_stack *stack)
{
	int	temp;

	if (stack == NULL || stack->next == NULL)
		return ;
	temp = stack->number;
	stack->number = stack->next->number;
	stack->next->number = temp;
}

/* sa (swap_a) */
void	swap_a(t_stack **stack_a)
{
	swap(*stack_a);
	write(1, "sa\n", 3);
}

/* sb (swap_b) */
void	swap_b(t_stack **stack_b)
{
	swap(*stack_b);
	write(1, "sb\n", 3);
}

/* ss (swap_a && swap_b) */
void	swap_s(t_stack **stack_a, t_stack **stack_b)
{
	swap(*stack_a);
	swap(*stack_b);
	write(1, "ss\n", 3);
}
