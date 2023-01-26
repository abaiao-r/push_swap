/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 16:34:24 by abaiao-r          #+#    #+#             */
/*   Updated: 2023/01/26 21:10:48 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (ft_error());
	if (!check_argv(argv))
		ft_error();
	stack_b = NULL;
	stack_a = ft_create_stack(argv);
}

/* i = argc

		stack_a = (t_list **)ft_calloc(1, sizeof(t_list));
	i = 0;
	while (i < argc)
	{{
    "[c]": {
        "editor.defaultFormatter": "keyhr.42-c-format"
    },
}
		i++;
	} */