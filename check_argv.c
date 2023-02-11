/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 15:42:17 by andrefranci       #+#    #+#             */
/*   Updated: 2023/02/10 23:11:46 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Funtion to check if argv is a number.
(PS: isolate test is commented at the end of file)*/
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
/* Funtion to check if there is duplicate argv. 
(PS: to test in an isolate way you can replace argv_duplicate per main)*/
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

/* Funtion to check if argv is a integer. */
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

/* main to test check_argv */
/* int	main(void)
{
	argv[1][] = "123";
	argv[2][] = "345";
	check_argv(&argv);
	printf("argv válido: %d", check_argv(&argv));

} */
