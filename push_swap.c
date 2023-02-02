/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 16:34:24 by abaiao-r          #+#    #+#             */
/*   Updated: 2023/02/02 16:29:57 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (ft_error());
	if (!check_argv(argv))
		ft_error();
	stack_b = NULL;
	stack_a = ft_create_stack(argv);
} */

/* main para testar a criacao do stack a; */
int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack *stack_a1;
	t_stack *stack_b;

	(void)argc;
	if (argc < 2)
		return (0);
	if (!check_argv(argv))
		return (ft_error());
	stack_b = NULL;
	stack_a = ft_create_stack(argv);
	stack_a1 = stack_a;

	while (stack_a)
	{
		printf("%d\n\n", stack_a->number);
		stack_a = stack_a->next;
	}
	push_b(&stack_a1, &stack_b);
	push_b(&stack_a1, &stack_b);
	print_stack(stack_b);

}

void print_stack(t_stack *stack)
{
	while (stack)
	{
		printf("\n%d\n\n", stack->number);
		stack = stack->next;
	}
}
