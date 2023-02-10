/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 19:44:50 by abaiao-r          #+#    #+#             */
/*   Updated: 2023/02/10 20:55:17 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* int	arguments_count(char **arguments_vector)
{
	int	i;

	if (arguments_vector == NULL)
		return (0);
	i = 0;
	while (arguments_vector[i] != 0)
	{
		i++;
	}
	return (i);
} */

char	**arg_parser(int argc, char **argv)
{
	char	**arguments_vector;
	(void) argc;

	arguments_vector = ft_split(argv[1], ' ');
	return (arguments_vector);
}

static int	count_words(char const *s, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	size_t i;
	size_t j;
	size_t start;
	size_t count;
	char **split;

	count = count_words((char *)s, c);
	split = malloc(sizeof(char *) * (count + 1));
	if (!s || !(split))
		return (0);
	i = 0;
	j = 0;
	while (s[i] && j < count)
	{
		while (s[i] == c && s[i])
			i++;
		start = i;
		while (s[i] != c && s[i])
			i++;
		split[j++] = ft_substr(s, start, i - start);
	}
	split[count] = 0;
	return (split);
}