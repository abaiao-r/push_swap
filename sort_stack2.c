/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefrancisco <andrefrancisco@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:30:03 by andrefranci       #+#    #+#             */
/*   Updated: 2023/02/12 19:08:07 by andrefranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* The function sort_stack_n sorts the elements in a stack represented 
by the pointer stack_a. Radix Sort!!! The sorting is done by converting 
each element in the stack into binary representation, then sorting the 
elements in the stack based on each binary digit, starting from the most 
significant bit (MSB) to the least significant bit (LSB).

The function uses the helper function count_digits_binary to determine the 
number of binary digits needed to represent the size of the stack. It then 
uses a loop to sort the elements based on each binary digit, from the MSB 
to the LSB.

For each iteration of the loop, the function iterates through each element 
in the stack and checks its binary representation for the current binary 
digit. If the digit is '1', the function rotates the stack by calling the 
rotate_a function. If the digit is '0', the function pushes the element to 
another stack represented by the pointer stack_b by calling the push_b function.

After each iteration of the loop, the function pushes all elements from the 
stack_b back to the stack_a using the push_a function. The loop continues 
until all elements in the stack are sorted based on all binary digits or 
until the stack is already sorted, as determined by the check_sorted 
function. */
void	sort_stack_n(t_stack **stack_a, t_stack **stack_b)
{
	int	i;
	int	j;
	int	len;

	len = ft_lstsize(*stack_a);
	i = count_digits_binary(ft_lstsize(*stack_a)) - 1;
	while (i >= 0 && !check_sorted(stack_a))
	{
		j = 0;
		while (j < len)
		{
			if ((*stack_a)->rank_binary[i] == '1')
				rotate_a(stack_a);
			else
				push_b(stack_a, stack_b);
			j++;
		}
		while (*stack_b != NULL)
			push_a(stack_b, stack_a);
		i--;
	}
}

/* code that works but is very unificient */
/* void	sort_stack_n(t_stack **stack_a, t_stack **stack_b)
{
	int	stack_size;

	stack_size = ft_lstsize(*stack_a);
	while (stack_size > 3)
	{
		*stack_a = rotate_to_lowest_number(*stack_a);
		push_b(stack_a, stack_b);
		stack_size--;
	}
	sort_stack_3(stack_a);
	while (*stack_b != NULL)
	{
		push_a(stack_b, stack_a);
	}
}
 */