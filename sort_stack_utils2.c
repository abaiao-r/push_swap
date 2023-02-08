/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_utils2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 18:01:05 by abaiao-r          #+#    #+#             */
/*   Updated: 2023/02/08 19:15:10 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_ranks(t_stack **stack_a)
{
	t_stack	*current;
	t_stack	*temp;
	int		rank;

	current = (*stack_a);
	while (current != NULL)
	{
		rank = 1;
		temp = (*stack_a);
		while (temp != NULL)
		{
			if (temp->number < current->number)
			{
				rank++;
			}
			temp = temp->next;
		}
		current->rank = rank;
		current = current->next;
	}
}
