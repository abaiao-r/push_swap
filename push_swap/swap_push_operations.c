/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_push_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedperei <pedperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 00:51:39 by pedperei          #+#    #+#             */
/*   Updated: 2023/01/01 19:34:33 by pedperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*chama as funcções com os argumentos necessários
para representar os 3 casos de swap: sa, sb, ss e faz os prints*/
void	swap_p(t_int_node **stack_a, t_int_node **stack_b, char c)
{
	if (c == 'a')
	{
		swap(stack_a);
		write(1, "sa\n", 3);
	}
	if (c == 'b')
	{
		swap(stack_b);
		write(1, "sb\n", 3);
	}
	if (c == 's')
	{
		swap(stack_a);
		swap(stack_b);
		write(1, "ss\n", 3);
	}
}

/*chama as funcções com os argumentos necessários
para representar os 2 casos de push: pa, pb e faz os prints*/
void	push_p(t_int_node **stack_1, t_int_node **stack_2, char c)
{
	if (c == 'a')
	{
		push(stack_2, stack_1);
		write(1, "pa\n", 3);
	}
	if (c == 'b')
	{
		push(stack_1, stack_2);
		write(1, "pb\n", 3);
	}
}

/*chama as funcções com os argumentos necessários
para representar os 2 casos de rotate: ra, rb, rr e faz os prints*/
void	rotate_p(t_int_node **stack_a, t_int_node **stack_b, char c)
{
	if (c == 'a')
	{
		rotate(stack_a);
		write(1, "ra\n", 3);
	}
	if (c == 'b')
	{
		rotate(stack_b);
		write(1, "rb\n", 3);
	}
	if (c == 's')
	{
		rotate(stack_a);
		rotate(stack_b);
		write(1, "rr\n", 3);
	}
}

/*chama as funcções com os argumentos necessários
para representar os 2 casos de reverse_rotate: rra, rrb, rrr e faz os prints*/
void	r_rotate_p(t_int_node **stack_a, t_int_node **stack_b, char c)
{
	if (c == 'a')
	{
		reverse_rotate(stack_a);
		write(1, "rra\n", 4);
	}
	if (c == 'b')
	{
		reverse_rotate(stack_b);
		write(1, "rrb\n", 4);
	}
	if (c == 's')
	{
		reverse_rotate(stack_a);
		reverse_rotate(stack_b);
		write(1, "rrr\n", 4);
	}
}
