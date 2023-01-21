/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedperei <pedperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 20:15:12 by pedperei          #+#    #+#             */
/*   Updated: 2023/01/05 17:29:26 by pedperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*atualiza o campo dos indexes dos vários t_int_nodes da lista*/
void	refresh_index(t_int_node **stack)
{
	t_int_node	*temp;
	int			index;

	temp = (*stack);
	index = 0;
	while (temp != NULL)
	{
		temp->index = index;
		temp = temp->next;
		index++;
	}
}

/*troca os 2 primeiros elementos da lista,
no caso não haver 2 elementos não se faz nada*/
void	swap(t_int_node **stack)
{
	t_int_node	*temp;

	if (ft_lstsize(*stack) < 2)
		return ;
	temp = (*stack);
	(*stack) = (*stack)->next;
	temp->next = (*stack)->next;
	(*stack)->next = temp;
	refresh_index(stack);
}

/*põe o primeiro elemento da stack_1 no topo da stack_2 e
atauliza-se o inicio da lista (*stack_1) = (*stack_1)->next.
Se não houver nenhum elemento na stack_1 não se faz nada.*/
void	push(t_int_node **stack_1, t_int_node **stack_2)
{
	t_int_node	*head;

	if (ft_lstsize(*stack_1) < 1)
		return ;
	head = (*stack_1);
	(*stack_1) = (*stack_1)->next;
	ft_lstadd_front(stack_2, head);
	refresh_index(stack_1);
	refresh_index(stack_2);
}

/*passa o primeiro elemento da lista para final da mesma,
no caso não haver 2 elementos não se faz nada*/
void	rotate(t_int_node **stack)
{
	t_int_node	*temp;
	t_int_node	*head;

	if (ft_lstsize(*stack) < 2)
		return ;
	temp = (*stack);
	head = (*stack)->next;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = (*stack);
	(*stack)->next = NULL;
	(*stack) = head;
	refresh_index(stack);
}

/*passa o ultimo elemento da lista para o inicio da mesma,
no caso não haver 2 elementos não se faz nada*/
void	reverse_rotate(t_int_node **stack)
{
	t_int_node	*temp;
	t_int_node	*head;
	t_int_node	*end;

	if (ft_lstsize(*stack) < 2)
		return ;
	temp = (*stack);
	head = (*stack);
	while (temp->next != NULL)
	{
		if (temp->next->next == NULL)
			end = temp;
		temp = temp->next;
	}
	(*stack) = temp;
	temp->next = head;
	end->next = NULL;
	refresh_index(stack);
}
