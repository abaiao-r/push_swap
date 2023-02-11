/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 16:33:03 by abaiao-r          #+#    #+#             */
/*   Updated: 2023/02/08 13:20:06 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack_5(t_stack **stack_a, t_stack **stack_b)
{
	*stack_a = rotate_to_lowest_number(*stack_a);
	push_b(stack_a, stack_b);
	sort_stack_4(stack_a, stack_b);
	push_a(stack_b, stack_a);
}

void	sort_stack_4(t_stack **stack_a, t_stack **stack_b)
{
	*stack_a = rotate_to_lowest_number(*stack_a);
	push_b(stack_a, stack_b);
	sort_stack_3(stack_a);
	push_a(stack_b, stack_a);
}

void	sort_stack_3(t_stack **stack_a)
{
	int	a;
	int	b;
	int	c;

	a = (*stack_a)->number;
	b = (*stack_a)->next->number;
	c = (*stack_a)->next->next->number;
	if (a < b && b > c && c > a)
	{
		swap_a(stack_a);
		rotate_a(stack_a);
	}
	else if (a > b && c > a && c > b)
		swap_a(stack_a);
	else if (a < b && b > c && c < a)
		reverse_rotation_a(stack_a);
	else if (a > b && b < c)
		rotate_a(stack_a);
	else if (a > b && b > c)
	{
		swap_a(stack_a);
		reverse_rotation_a(stack_a);
	}
}

void	sort_stack_2(t_stack **stack_a)
{
	if ((*stack_a)->number > (*stack_a)->next->number)
		swap_a(stack_a);
}

void	sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	(void)(*stack_b);
	if (check_sorted(stack_a))
		return ;
	if (ft_lstsize(*stack_a) == 2)
		sort_stack_2(stack_a);
	else if (ft_lstsize(*stack_a) == 3)
		sort_stack_3(stack_a);
	else if (ft_lstsize(*stack_a) == 4)
		sort_stack_4(stack_a, stack_b);
	else if (ft_lstsize(*stack_a) == 5)
		sort_stack_5(stack_a, stack_b);
	else
		sort_stack_n(stack_a, stack_b);
}
