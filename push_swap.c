/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefrancisco <andrefrancisco@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 16:34:24 by abaiao-r          #+#    #+#             */
/*   Updated: 2023/01/25 16:32:22 by andrefranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_stack *stack_a;
	t_stack *stack_b;


    if (argc < 2)
        return (ft_error());
    if (!check_argv)
        ft_error();
	stack_b = NULL; 
	stack_a = ft_create_stack(argc, argv);
	

	/* i = argc

		stack_a = (t_list **)ft_calloc(1, sizeof(t_list));
	i = 0;
	while (i < argc)
	{
		i++;
	} */
}