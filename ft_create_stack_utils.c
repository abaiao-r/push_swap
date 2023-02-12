/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_stack_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefrancisco <andrefrancisco@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 13:54:56 by abaiao-r          #+#    #+#             */
/*   Updated: 2023/02/12 18:22:28 by andrefranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/* Returns the last element of a list */
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

/* Adds a element of a list to the back to of any list indicated. */
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

/* creates a new list.  */
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
	return (connect);
}

/* The code implements the function ft_lstclear which takes 
a pointer to a linked list of type t_stack and frees the memory 
associated with that list.

The function first checks if the argument lst is NULL or if the 
linked list it points to is empty. If either of these conditions 
is true, the function returns immediately without doing anything.

If the linked list is not empty, the function enters a loop that 
continues until all elements in the list have been freed. 
Within the loop, the function performs the following steps for each iteration:

Saves a pointer to the next element in the list into a temporary 
variable temp.
Frees the memory associated with the rank binary representation 
of the current element.
Frees the memory associated with the current element.
Sets the linked list pointer lst to point to the next element in 
the list as stored in temp.
The loop continues until all elements in the linked list have been 
freed, at which point the function returns. */
void	ft_lstclear(t_stack **lst)
{
	t_stack	*temp;

	if (!lst || !*lst)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		free((*lst)->rank_binary);
		free(*lst);
		*lst = temp;
	}
}

/* This code defines a function ft_lst_before_last, which takes a 
pointer to a t_stack structure (i.e., a linked list) as an argument 
and returns a pointer to the node in the linked list immediately 
before the last node. */
t_stack	*ft_lst_before_last(t_stack *lst)
{
	while (lst && lst->next && lst->next->next)
	{
		lst = lst->next;
	}
	return (lst);
}
