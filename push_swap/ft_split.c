/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedperei <pedperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 22:51:46 by pedperei          #+#    #+#             */
/*   Updated: 2023/01/05 14:59:27 by pedperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	**free_mem(char **array_str)
{
	int	i;

	i = 0;
	while (array_str[i] != NULL)
	{
		free(array_str[i]);
		i++;
	}
	free(array_str);
	return (NULL);
}

/*Conta nº strings que vao estar alocadas*/
/*no double pointer(sem contar com o ultimo NULL)*/
int	nbr_strings(char const *str, char c)
{
	int	i;
	int	nbr_strings;

	nbr_strings = 0;
	i = 0;
	if (str[i] != c && str[i] != '\0')
		nbr_strings = 1;
	while (str[i] != '\0')
	{
		if (str[i] == c)
		{
			while (str[i] == c)
				i++;
			if (str[i] != '\0')
				nbr_strings++;
		}
		else
			i++;
	}
	return (nbr_strings);
}

/*e passado como argumento a posicao onde se esta na string principal*/
/*itera-se a string ate se encontrar o caracter do separador ou NULL*/
/*aloca-se a memoria para a string após se descobrir 
o comprimento que vai ter (i)*/
/*preenche-se a string criada com os valores da string original*/
/*NULL terminator no final de cada string criada*/
char	*str_alloc(char const *s, char c, int pos)
{
	int		i;
	char	*str;

	i = 0;
	if (s[pos + i] == '\0')
		return (NULL);
	while (s[pos + i] != c && s[pos + i] != '\0')
	{
		i++;
	}
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s[pos + i] != c && s[pos + i] != '\0')
	{
		str[i] = s[pos + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

/*faz sentido ter esta restrição? s[i] == '\0'*/
/*aloca memoria para o array de strings 
(considerando o ultimo elemento a apontar para NULL)*/
/*itera entre as várais strings do array*/
/*preenche as várias strings*/
/*itera-se a string original para saber em que posição 
se esta de forma a passar para a funcao str_alloc*/
/*incrementa-se j + 1 para passar o elemento do delimiter*/
char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**array_str;

	i = 0;
	j = 0;
	array_str = (char **)malloc(sizeof(char *) * (nbr_strings(s, c) + 1));
	if (!(array_str))
		return (NULL);
	while (i < nbr_strings(s, c))
	{
		while (s[j] == c)
			j++;
		array_str[i] = str_alloc(s, c, j);
		if (!(array_str[i]))
			return (free_mem(array_str));
		while (s[j] != c && s[j] != '\0')
			j++;
		j++;
		i++;
	}
	array_str[i] = 0;
	return (array_str);
}
