/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefrancisco <andrefrancisco@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 15:42:17 by andrefranci       #+#    #+#             */
/*   Updated: 2023/02/06 14:51:36 by andrefranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Função para verificar se argv é um número.*/
int	argv_is_number(char *argv)
{
	int	i;

	i = 0;
	if (ft_issign(argv[i]) && argv[i + 1] != '\0')
		i++;
	while (argv[i] != '\0')
	{
		if (!ft_isdigit(argv[i]))
		{
			return (0);
		}
		i++;
	}
	return (1);
}

/* int	argv_iszero(char *argv)
{
	int	i;

	i = 0;
	if (ft_issign(argv[i]))
		i++;
	while (argv[i] != '\0' && argv[i] == '0')
		i++;
	if (argv[i] != '\0')
		return (0);
	else
		return (1);
} */
/* Função para verificar se há argv duplicados. 
(PS: para testar de forma isolada basta substituir argv_duplicate por main) */
int	argv_duplicate(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = i + 1;
		while (argv[j])
		{
			if (ft_atol(argv[i]) == ft_atol(argv[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	argv_is_int(char **argv)
{
	int	i;
	int	len_argv;

	i = 1;
	len_argv = ft_strlen(argv[i]);
	while (argv[i] != NULL)
	{
		if (len_argv > 10)
			return (0);
		if (ft_atol(argv[i]) > 2147483647 || ft_atol(argv[i]) < -2147483648)
			return (0);
		i++;
	}
	return (1);
}

int	check_argv(char **argv)
{
	int	i;

	i = 1;
	while (argv[i] != NULL)
	{
		if (!argv_is_number(argv[i]))
			return (0);
		if (argv_duplicate(argv))
			return (0);
		if (!argv_is_int(argv))
			return (0);
		i++;
	}
	return (1);
}

/* Legacy code */
/* int	check_argv(char **argv)
{
	int	i;

	i = 1;
	while (argv[i] != NULL)
	{
		if (!argv_is_number(argv[i]))
			return (0);
		i++;
	}
	if (argv_duplicate(argv))
		return (0);
	if (ft_atoll(argv[i]) > INT_MAX || ft_atoll(argv[i]) < INT_MIN)
		return (0);
	else
		return (1);
} */

/* main para testar check_argv */
/* int	main(void)
{
	argv[1][] = "123";
	argv[2][] = "345";
	check_argv(&argv);
	printf("argv válido: %d", check_argv(&argv));

} */

/* main para testar a função	argv_is_number
(PS: fica mais legível se testares caso a caso) */
/* int main(void)
{
	char argv[] = "123";
	printf("123 is a number: %d", argv_is_number(argv));

	char argv1[] = "-123";
	printf("\n -123 is a number: %d ", argv_is_number(argv1));

	char argv2[] = "+-123";
	printf("\n +-123 is a number: %d ", argv_is_number(argv2));

	char argv3[] = "1a23";
	printf("\n 1a23 is a number: %d ", argv_is_number(argv3));

	char argv4[] = "Hello1";
	printf("\n Hello1 is a number: %d ", argv_is_number(argv4));
} */