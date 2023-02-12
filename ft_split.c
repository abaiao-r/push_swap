/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefrancisco <andrefrancisco@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 19:44:50 by abaiao-r          #+#    #+#             */
/*   Updated: 2023/02/12 18:33:54 by andrefranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*  This is a function ft_split that takes in two parameters: 
s which is a string and c which is a character. The function 
splits the string s into multiple strings and returns the 
resulting array of strings.

The function count_words is a helper function used to count 
the number of substrings that the original string s will be 
split into. The function takes in two parameters: s which is 
the original string and c which is the character to split the 
string on. It iterates over the string and increments the count 
whenever it encounters a character that is not equal to c and is 
either followed by a c or the end of the string.

In the main ft_split function, an array of strings split is 
created using malloc by allocating memory for count strings plus 
one additional string for the end of the array. The function then 
iterates over the string s and splits it into substrings whenever 
it encounters a character equal to c. The substrings are stored in 
the split array, and the function returns the resulting array of strings.*/
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
