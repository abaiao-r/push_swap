/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefrancisco <andrefrancisco@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 19:44:50 by abaiao-r          #+#    #+#             */
/*   Updated: 2023/02/12 12:39:50 by andrefranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	size_t	i;
	size_t	j;
	size_t	start;
	size_t	count;
	char	**split;

	count = count_words((char *)s, c) + 1;
	split = malloc(sizeof(char *) * (count + 1));
	if (!s || !(split))
		return (0);
	i = 0;
	j = 1;
	while (s[i] && j < count)
	{
		while (s[i] == c && s[i])
			i++;
		start = i;
		while (s[i] != c && s[i])
			i++;
		split[j++] = ft_substr(s, start, i - start);
	}
	split[count] = '\0';
	return (split);
}

/* Main to test ft_split */
/* int		main(int argc, char **argv)
{
		(void) argc;
		char **tmp;

	tmp = ft_split(argv[1], ' ');
	printf ("%s", tmp[1]);
	return (0);
} */
