/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedperei <pedperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 13:07:32 by pedperei          #+#    #+#             */
/*   Updated: 2023/01/05 18:04:09 by pedperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*print error */
int	print_error(void)
{
	write(1, "Error\n", 6);
	return (0);
}

/*faz o check se todos os argumentos passados são digitos
ou -(seguidos de um digito) no caso de passarmos numeros negativos
pode haver white space entre os numeros
No caso de não se cumprir os criterios retorna-se um mensagem de erro*/
int	check_argv_type(char **argv)
{
	int	i;
	int	j;

	i = 0;
	if (!argv[i])
		return (print_error());
	while (argv[i] != NULL)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			while (argv[i][j] == 32 || (argv[i][j] >= 9 && argv[i][j] <= 13))
				j++;
			if (!(ft_isdigit(argv[i][j])) && !(j == 0 && argv[i][j] == '-'
					&& ft_isdigit(argv[i][j + 1])))
				return (print_error());
			j++;
		}
		i++;
	}
	return (1);
}

/*faz o check se todos os nºs estao dentro dos limites (int min e max) e vê se
não existem numeros duplicados (comparando strings - ft_strcmp == 0 - nº igual)
Retorna-se uma mensagem de erro no caso de não serem cumpridos os criterios*/
int	check_argv_dups(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i] != NULL)
	{
		if (ft_atoi(argv[i]) > INT_MAX || ft_atoi(argv[i]) < INT_MIN)
			return (print_error());
		j = 0;
		while (argv[j] != NULL)
		{
			if (!(ft_strcmp(argv[i], argv[j])) && (i != j))
				return (print_error());
			j++;
		}
		i++;
	}
	return (1);
}

/*No caso dos argumentos serem passados em texto (ficando tudo no argv[1])
utiliza-se o ft_slip para criar um char** com os varios numeros para ordenar*/
char	**arg_parser(int argc, char **argv)
{
	char	**args;

	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
		args = &argv[1];
	return (args);
}

/*faz free do char** criado no caso dos argumentos 
terem sido passados em texto ficando tudo no argv[1]*/
int	free_args(char **args, int n_args, int flag)
{
	int	i;

	i = 0;
	if (flag == 2)
	{
		while (i <= n_args)
		{
			free(args[i]);
			i++;
		}
		free(args);
	}
	return (0);
}
