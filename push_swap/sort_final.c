/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_final.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedperei <pedperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 11:20:38 by pedperei          #+#    #+#             */
/*   Updated: 2023/01/01 17:23:17 by pedperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*ordena lista com 2 numeros*/
void	sort_2(t_int_node **stack_a, t_int_node **stack_b)
{
	t_int_node	*temp;

	temp = (*stack_a);
	if (temp->rank > temp->next->rank)
		swap_p(stack_a, stack_b, 'a');
}

/*chama as varias funcoes de ordenacao conforme o nº de numeros da lista
se a lista tiver mais de 5 elementos utiliza-se o radix sort*/
void	sort_final(t_int_node **stack_a, t_int_node **stack_b)
{
	if (is_sorted(stack_a))
		return ;
	if (ft_lstsize(*stack_a) == 2)
		sort_2(stack_a, stack_b);
	else if (ft_lstsize(*stack_a) == 3)
		sort_3(stack_a, stack_b);
	else if (ft_lstsize(*stack_a) == 4)
		sort_4(stack_a, stack_b);
	else if (ft_lstsize(*stack_a) == 5)
		sort_5(stack_a, stack_b);
	else
		radix_sort(stack_a, stack_b);
}
