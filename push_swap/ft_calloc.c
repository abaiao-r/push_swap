/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedperei <pedperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 12:27:16 by pedperei          #+#    #+#             */
/*   Updated: 2022/11/12 18:55:00 by pedperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*temp;

	i = 0;
	temp = (unsigned char *)s;
	while (i < n)
	{
		temp[i] = 0;
		i++;
	}
}

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*temp;

	temp = (void *)malloc(size * nitems);
	if (! (temp))
		return (NULL);
	ft_bzero(temp, size * nitems);
	return (temp);
}
