/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_stack_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefrancisco <andrefrancisco@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 13:54:56 by abaiao-r          #+#    #+#             */
/*   Updated: 2023/02/06 14:51:35 by andrefranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_lstlast(t_stack *lst)
{
	if (!lst)
	{
		return (0);
	}
	while (lst != NULL)
	{
		if (!lst->next)
		{
			return (lst);
		}
		lst = lst->next;
	}
	return (lst);
}

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*last;

	if (lst)
	{
		if (*lst)
		{
			last = ft_lstlast(*lst);
			last->next = new;
		}
		else
		{
			*lst = new;
		}
	}
	return ;
}

t_stack	*ft_lstnew(int nbr)
{
	t_stack	*connect;

	connect = (t_stack *)malloc(sizeof(t_stack));
	if (!connect)
	{
		return (NULL);
	}
	connect->number = nbr;
	connect->next = NULL;
	connect->previous = NULL;
	return (connect);
}

void	ft_lstclear(t_stack **lst, void (*del)(void *))
{
	t_stack	*temp;

	if (!lst || !*lst || !del)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		free(*lst);
		*lst = temp;
	}
}

t_stack	*ft_lst_before_last(t_stack *lst)
{
	while (lst && lst->next && lst->next->next)
	{
		lst = lst->next;
	}
	return (lst);
}
