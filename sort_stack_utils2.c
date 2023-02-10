/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_utils2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 18:01:05 by abaiao-r          #+#    #+#             */
/*   Updated: 2023/02/10 17:29:53 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* count the number of digits that a number will have in binary */
int	count_digits_binary(int rank)
{
	int	i;

	i = 0;
	if (rank == 0)
		return (1);
	while (rank > 0)
	{
		rank /= 2;
		i++;
	}
	return (i);
}

char	*convert_int_to_binary(int rank, int max)
{
	int		rank_max_digits;
	int		rank_current_digits;
	char	*binary_rank;
	int		i;

	rank_max_digits = count_digits_binary(max);
	rank_current_digits = count_digits_binary(rank);
	binary_rank = (char *)ft_calloc(rank_max_digits, (sizeof(char) + 1));
	if (!binary_rank)
		return (0);
	binary_rank[rank_max_digits] = '\0';
	i = 0;
	while (i < rank_max_digits - rank_current_digits)
	{
		binary_rank[i] = '0';
		i++;
	}
	while (rank > 0)
	{
		rank_max_digits--;
		binary_rank[rank_max_digits] = rank % 2 + '0';
		rank = rank / 2;
	}
	return (binary_rank);
}

int	assign_ranks(t_stack **stack)
{
	t_stack	*current;
	t_stack	*temp;
	int		rank;

	current = (*stack);
	temp = (*stack);
	while (current != NULL)
	{
		rank = 1;
		temp = (*stack);
		while (temp != NULL)
		{
			if (temp->number < current->number)
			{
				rank++;
			}
			temp = temp->next;
		}
		current->rank = rank;
		current->rank_binary = convert_int_to_binary(rank, ft_lstsize(*stack));
		if (!current->rank_binary)
			return (0);
		current = current->next;
	}
	return (1);
}
