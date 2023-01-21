/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_aux.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedperei <pedperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 21:06:47 by pedperei          #+#    #+#             */
/*   Updated: 2023/01/01 18:32:05 by pedperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*vê se a lista já está ordenada do mais pequeno para o maior*/
int	is_sorted(t_int_node **stack)
{
	t_int_node	*temp;

	temp = (*stack);
	while (temp->next != NULL)
	{
		if (!(temp->num < temp->next->num))
			return (0);
		temp = temp->next;
	}
	return (1);
}

/*ordena lista com 3 elementos
trata de todos os casos possiveis um a um*/
void	sort_3(t_int_node **stack_a, t_int_node **stack_b)
{
	int	top;
	int	mid;
	int	bot;

	top = (*stack_a)->rank;
	mid = (*stack_a)->next->rank;
	bot = (*stack_a)->next->next->rank;
	if (top < mid && mid > bot && top < bot)
	{
		swap_p(stack_a, stack_b, 'a');
		rotate_p(stack_a, stack_b, 'a');
	}
	else if (top < mid && mid > bot && top > bot)
		r_rotate_p(stack_a, stack_b, 'a');
	else if (top > mid && mid > bot)
	{
		swap_p(stack_a, stack_b, 'a');
		r_rotate_p(stack_a, stack_b, 'a');
	}
	else if (top > mid && mid < bot && top < bot)
		swap_p(stack_a, stack_b, 'a');
	else if (top > mid && mid < bot && top > bot)
		rotate_p(stack_a, stack_b, 'a');
}

/* passa o numero com rank 1 da stack_a para a stack_b e 
chama-se a funcao de ordenacao com 3 elementos e
volta-se a passar o numero com rank 1 para o topo da stack_a*/
void	sort_4(t_int_node **stack_a, t_int_node **stack_b)
{
	t_int_node	*temp;
	int			len;

	temp = (*stack_a);
	len = ft_lstsize(*stack_a);
	while (len > 0)
	{
		if (temp->rank == 1)
			push_p(stack_a, stack_b, 'b');
		else
			rotate_p(stack_a, stack_b, 'a');
		temp = (*stack_a);
		len--;
	}
	sort_3(stack_a, stack_b);
	push_p(stack_a, stack_b, 'a');
}

/* passa os numeros com rank 1 e 2 da stack_a para a stack_b e
ordena-se os 2 numeros do maior para o menor.
Chama-se a funcao de ordenacao com 3 elementos e
volta-se a passar o numeros com rank 1 e 2 para o topo da stack_a*/
void	sort_5(t_int_node **stack_a, t_int_node **stack_b)
{
	t_int_node	*temp;
	int			len;

	temp = (*stack_a);
	len = ft_lstsize(*stack_a);
	while (len > 0)
	{
		if (temp->rank == 1 || temp->rank == 2)
			push_p(stack_a, stack_b, 'b');
		else
			rotate_p(stack_a, stack_b, 'a');
		temp = (*stack_a);
		len--;
	}
	sort_3(stack_a, stack_b);
	temp = (*stack_b);
	if (temp->rank < temp->next->rank)
		swap_p(stack_a, stack_b, 'b');
	push_p(stack_a, stack_b, 'a');
	push_p(stack_a, stack_b, 'a');
}

/*vê-se o numero de digitos em binario 
do rank mais elevado(nº de elementos da lista) e subtrai-se - 1
para utilizar a sua posicao no char* (posição i).
De seguida vemos se o digito na posição i é 1 ou 0:
1 - rotate stack_a, 0 - push do numero para a stack_b
Faz-se esta logica para tods os numeros da lista (j < len).
Depois faz-se push dos nº que foram para a stack_b de novo para a stack_a.
Repete-se esta lógica i vezes (nº digitos em binario do max rank).
Comeca-se no digito mais a direita (que representa o numero com menor valor)
e termina-se no mais a esquerda (que representa o numero com maior valor)*/
void	radix_sort(t_int_node **stack_a, t_int_node **stack_b)
{
	int	i;
	int	j;
	int	len;

	i = count_digits_binary(ft_lstsize(*stack_a)) - 1;
	len = ft_lstsize(*stack_a);
	while (i >= 0)
	{
		j = 0;
		while (j < len)
		{
			if ((*stack_a)->rank_bin[i] == '1')
				rotate_p(stack_a, stack_b, 'a');
			else
				push_p(stack_a, stack_b, 'b');
			j++;
		}
		while (ft_lstsize(*stack_b) > 0)
			push_p(stack_a, stack_b, 'a');
		i--;
	}
}
