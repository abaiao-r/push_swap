/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 20:15:12 by pedperei          #+#    #+#             */
/*   Updated: 2023/01/21 16:24:11 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_front(t_int_node **lst, t_int_node *new)
{
	new->next = *lst;
	*lst = new;
}

void	ft_lstadd_back(t_int_node **lst, t_int_node *new)
{
	t_int_node	*temp;

	temp = *lst;
	if (temp == NULL)
		*lst = new;
	else
	{
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = new;
	}
}

/*aloca memoria para um t_int_node e inicializa os seus valores*/
t_int_node	*ft_new_t_int_node(long int num, int index)
{
	t_int_node	*new;

	new = (t_int_node *) ft_calloc(1, sizeof(t_int_node));
	if (new == NULL)
		return (NULL);
	new->num = (int)num;
	new->index = index;
	new->rank = 0;
	new->rank_bin = NULL;
	new->next = NULL;
	return (new);
}

int	ft_lstsize(t_int_node *lst)
{
	t_int_node	*temp;
	int			i;

	temp = lst;
	i = 1;
	if (lst == NULL)
		return (0);
	while (temp->next != NULL)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}

t_int_node	*search_node(t_int_node **stack, int index)
{
	t_int_node	*temp;

	temp = (*stack);
	while (temp != NULL)
	{
		if (temp->index == index)
			break ;
		temp = temp->next;
	}
	return (temp);
}
