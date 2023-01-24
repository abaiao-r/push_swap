/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefrancisco <andrefrancisco@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 17:04:06 by andrefranci       #+#    #+#             */
/*   Updated: 2023/01/24 18:56:45 by andrefranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_create_stack(int argc, char **argv)
{
	t_stack *stack_a;
	long int index_node;
	int i;

	stack_a = NULL; 
    stack_a = (t_stack *)malloc(sizeof(t_stack));

    i = 0;
	while (i < argc)
	{
		index_node = ft_atoi(argv[i]);
        ft_lstadd_back (stack_a, t_stack_);
        i++;
	}

	return (stack_a);
}