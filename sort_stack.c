/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 16:33:03 by abaiao-r          #+#    #+#             */
/*   Updated: 2023/02/04 17:26:14 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack_3(t_stack **stack_a, t_stack **stack_b)
{
    
}

void	sort_stack_2(t_stack **stack_a, t_stack **stack_b)
{
	if ((*stack_a)->number > (*stack_a)->next->number)
		swap_a(stack_a);
}

int	check_sorted(t_stack **stack_a)
{
	while ((*stack_a)->next != NULL)
	{
		if ((*stack_a)->number > (*stack_a)->next->number)
			return (0);
		else
			return (1);
	}
}

void	sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	if (check_sorted(stack_a))
		return ;
	if (ft_lstsize(*stack_a) == 2)
		sort_stack_2(stack_a, stack_b);
	else if (ft_lstsize(*stack_a) == 3)
		sort_stack_3(stack_a, stack_b);
	else if (ft_lstsize(*stack_a) == 4)
		sort_stack_4(stack_a, stack_b);
	else if (ft_lstsize(*stack_a) == 5)
		sort_stack_5(stack_a, stack_b);
	else
		sort_stack_n(stack_a, stack_b);
}