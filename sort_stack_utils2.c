/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_utils2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefrancisco <andrefrancisco@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 18:01:05 by abaiao-r          #+#    #+#             */
/*   Updated: 2023/02/09 18:59:45 by andrefranci      ###   ########.fr       */
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

char	*convert_int_to_binary(int rank)
{
	int		rank_max_digits;
	int		rank_current_digits;
	char	*binary_rank;
	int		i;

	rank_max_digits = count_digits_binary(ft_lstsize(*stack));
	rank_current_digits = count_digits_binary(rank);
	binary_rank = (char *)ft_calloc(rank_max_digits, (sizeof(char) + 1));
	if (!binary_rank)
		return (0);
	binary_rank[rank_max_digits] = '\0';
	i = 0;
	while (i < rank_max_digits - rank_current_digits)
	{
		binary_rank = '0';
		i++;
	}
	while (rank > 0)
	{
		rank_max_digits--;
		binary_rank[rank_max_digits] = rank % 2;
		rank = rank / 2;
	}
	return (binary_rank);
}

void	assign_ranks(t_stack **stack)
{
	t_stack	*current;
	t_stack	*temp;
	int		rank;

	current = (*stack);
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
		current->rank_binary = convert_int_to_binary(rank, *stack);
		if (!current->rank_binary)
			return (0);
		current = current->next;
	}
}
