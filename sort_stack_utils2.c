/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_utils2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefrancisco <andrefrancisco@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 18:01:05 by abaiao-r          #+#    #+#             */
/*   Updated: 2023/02/12 17:37:58 by andrefranci      ###   ########.fr       */
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

/* The function convert_int_to_binary is used to convert 
a decimal number (rank) to its binary representation as a string. 
The function first calculates the maximum number of digits that the 
binary representation of the highest-ranked number in the list will 
have (rank_max_digits). The number of digits that the current rank (rank) 
will have is also calculated (rank_current_digits).

A string of rank_max_digits characters is then allocated using the 
ft_calloc function, and is initialized to '\0' to ensure that it is 
a null-terminated string.

Next, a loop is executed that adds zeros to the beginning of the string 
until i is equal to rank_max_digits - rank_current_digits. This is done 
to ensure that all binary representations of ranks will have the same 
number of digits.

Finally, another loop is executed that converts rank to its binary 
representation by repeatedly dividing it by 2 and adding the remainder to 
the string,
starting from the end of the string and working towards the beginning. 
The result of this function is the binary representation of rank 
as a string.  */
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

/* The assign_ranks function takes a double pointer to a linked list
 stack as an argument. It assigns a rank to each node of the linked
list based on the value of the node's number field. The rank is 
defined as the number of nodes in the linked list with a value 
lower than the current node's value. The function also converts 
the rank to binary and assigns it to the node's rank_binary field.

To calculate the rank, the function first sets a pointer current to
 the head of the linked list, and another pointer temp to the head 
 of the linked list as well. Then, it iterates through the linked 
 list using the current pointer, and for each node, it calculates 
 its rank by iterating through the linked list again using the temp 
 pointer and incrementing the rank counter whenever the temp node's 
 value is less than the current node's value. */
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
