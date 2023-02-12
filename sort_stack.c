/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefrancisco <andrefrancisco@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 16:33:03 by abaiao-r          #+#    #+#             */
/*   Updated: 2023/02/12 18:12:24 by andrefranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/* sort_stack_5 and sort_stack_4 do the following: 
(1) rotate stack_a till the smaller number is on the top of 
the stack, using the rotate_to_lowest_number function.
(2) push the smallest number to stack_b using push_b.
(3) use sort_satck_3 funtion to sort stack_a;
(4) push all numbers in stack_b to stack_a using push_a  */
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

/* This code is a sorting function for a stack containing 3 
elements. The stack is represented as a linked list where each 
node contains an integer, and the head of the list represents 
the top of the stack.

The function sorts the stack by rearranging the elements to be 
in ascending order. To do this, it first checks the values of the 
three elements, and then performs the appropriate operations on 
the stack to rearrange them. */
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

/*  The sort_stack function takes two pointers to the linked 
lists representing two stacks, Stack A and Stack B. 
The function check_sorted is used to check if the stack is already 
sorted, and the ft_lstsize function is used to get the size of the 
stack.
Similarly, if the stack size is 3, 4, or 5, it calls the corresponding 
functions sort_stack_3, sort_stack_4, and sort_stack_5. For larger 
stacks, the function calls sort_stack_n to sort the stack.
*/
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
