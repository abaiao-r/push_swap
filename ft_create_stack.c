/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefrancisco <andrefrancisco@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 17:04:06 by andrefranci       #+#    #+#             */
/*   Updated: 2023/01/31 18:57:35 by andrefranci      ###   ########.fr       */
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
int	main(int argc, char **argv)
{
	t_stack	*stack_a;

	(void)argc;
	if (argc < 2)
		return (ft_error());
	/* if (!check_argv(argv))
		return (ft_error()); */
	stack_a = ft_create_stack(argv);
	while (stack_a)
	{
		printf("%d\n", stack_a->number);
		stack_a = stack_a->next;
	}
	swap(stack_a);
}
