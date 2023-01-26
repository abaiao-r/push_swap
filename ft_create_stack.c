/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 17:04:06 by andrefranci       #+#    #+#             */
/*   Updated: 2023/01/26 20:59:16 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_create_stack(char **argv)
{
	int		number;
	int		i;
	t_stack	*stack_a;

	i = 1;
	number = 0;
	while (argv[i] != 0)
	{
		number = ft_atoi(argv[i]);
		if (i == 1)
		{
			stack_a = ft_lstnew(number);
		}
		else
		{
			ft_lstadd_back(&stack_a, ft_lstnew(number));
		}
		i++;
	}
	return (stack_a);
}

/* main para testar a criacao do stack a; */
/* int	main(int argc, char **argv)
{
	t_stack	*stack_a;

	(void)argc;

	stack_a = ft_create_stack(argv);
	while (stack_a)
	{
		printf("%d", stack_a->number);
		stack_a = stack_a->next;
	}
} */
